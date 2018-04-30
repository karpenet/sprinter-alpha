/*
 * WifiCommunication.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: karpenet
 */

#include "WifiCommunication.h"

WifiCommunication::WifiCommunication() {
	// TODO Auto-generated constructor stub
	  portOutgoing_ = 4999;
	  portIncoming_ = 4998;

}

WifiCommunication::~WifiCommunication() {
	// TODO Auto-generated destructor stub
}

bool WifiCommunication::initialize(){
  /* Reset Host IP availability flag */
  receivedHostIP_ = false;

  /* Connect to access point defined in WifiConfig */
  Serial.print("Connecting to WiFi SSID: "); Serial.println(WifiConfig::wifiSSID);
  Serial.print("Connecting using PW: "); Serial.println(WifiConfig::wifiPassword);

  /* Set WiFi in Station mode */
  WiFi.mode(WIFI_STA);

  /* Connect to configured AP */
  WiFi.begin(WifiConfig::wifiSSID, WifiConfig::wifiPassword);

  int tries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    tries++;
  }

  /* Set autoconnect and reconnect flag */
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);

  if(WiFi.status() == WL_CONNECTED) {
    /* Start listening for UDP packages */
    if(udp_.begin(portIncoming_)) {
      Serial.print("Connected AP: "); Serial.println(WifiConfig::wifiSSID);
      Serial.print("Local IP: "); Serial.println(WiFi.localIP());
      Serial.print("Listening on UDP port: "); Serial.println(portIncoming_);
    }


    return true;
  }
};

bool WifiCommunication::switchAP(String SSID, String password) {
  /* Disconnect from current AP if any */
  WiFi.disconnect();

  Serial.print("Connecting to WiFi SSID: "); Serial.println(SSID);
  Serial.print("Connecting using PW: "); Serial.println(password);

  /* Cast strings to char arrays */
  char SSIDChar[sizeof(char) * (SSID.length() + 1)];
  SSID.toCharArray(SSIDChar, sizeof(char) * (SSID.length() + 1));
  char pwChar[sizeof(char) * (password.length() + 1)];
  password.toCharArray(pwChar, sizeof(char) * (password.length() + 1));

  /* Reset ESP8266 in Station Mode */
  WiFi.mode(WIFI_STA);

  /* Connect to new access point with the channel specified */
  WiFi.begin(SSIDChar, pwChar, wifiChannel_);

  int tries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    tries++;
  }

  /* Set autoconnect and reconnect flag */
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);

  /* Restart UDP service */
  if(WiFi.status() == WL_CONNECTED) {
    /* Start listening for UDP packages */
    if(udp_.begin(portIncoming_)) {
      Serial.print("Connected AP: "); Serial.println(SSID);
      Serial.print("Listening on UDP port: "); Serial.println(portIncoming_);
      Serial.printf("BSSID: %s\n", WiFi.BSSIDstr().c_str());
    }

    return true;
  }
}

/* Wireless communication functions */
void WifiCommunication::sendMessage(String data) {
  /* Send message to host via UDP */
  sendUdpPacket(data);
}

int32_t WifiCommunication::receiveMessage(){
  return receiveUdpPacket();
};

/* -----------------------------*/
/*        Set functions         */
/* -----------------------------*/
void WifiCommunication::setPortIncoming(uint16_t port) {
  /* Assign new port */
  portIncoming_ = port;

  /* Stop listening to current port */
  udp_.stop();
  delay(250);

  if(udp_.begin(portIncoming_)) {
    Serial.print("Listening on UDP port: ");
    Serial.println(portIncoming_);
  } else {
    Serial.print("Failed to open UDP connection on port: ");
    Serial.println(portIncoming_);
  }
}

void WifiCommunication::setPortOutgoing(uint16_t port) {
  portOutgoing_ = port;

  Serial.print("Sending to UDP port: ");
  Serial.println(portOutgoing_);
}


void WifiCommunication::setHostIP(String hostIP) {
  /* Parse host IP */
  hostIPStr_ = hostIP;
  receivedHostIP_ = true;

  Serial.print("Sending to host IP: ");
  Serial.println(hostIPStr_);
}

bool WifiCommunication::setWifiChannel(uint8_t channel) {
  if(channel > 0 && channel < 13) {
    wifiChannel_ = channel;
    wifi_set_channel(channel);
    Serial.print("Switched to channel "); Serial.println(channel);
    return true;
  } else {
    return false;
  }
}
/* function to set the new SSID */
void WifiCommunication::setServerSSID(String ssid) {
  serverSSID_ = ssid;
}
/* function to set the new password */
void WifiCommunication::setServerPassword(String password) {
  serverPassword_ = password;
}

/* disconnects from the gateway AP, and connects to the main server */
void WifiCommunication::reconnectToMainHost(){
  switchAP(serverSSID_,serverPassword_);
}
/* -----------------------------*/
/*     Status functions         */
/* -----------------------------*/
bool WifiCommunication::isConnected() {
  if( WiFi.status() == WL_CONNECTED ) {
    return true;
  } else {
    return false;
  }
}

/* -----------------------------*/
/*        Get functions         */
/* -----------------------------*/
String WifiCommunication::getMACaddress(){
  /* Access the MAC address of the robot */
  byte mac[6];

  // E.g. "18:fe:34:d4:d8:fe
  WiFi.macAddress(mac); // obtaining the MAC address

  char macChar[50] = {0};
  sprintf(macChar,"%02x:%02x:%02x:%02x:%02x:%02x",
          mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
  return String(macChar);
}

//--------------------------------------------------------------------------
// Private Member Functions
//--------------------------------------------------------------------------
bool WifiCommunication::sendUdpPacket(String msg) {
  /* Allow background tasks of WiFi stack to execute */
  yield();

  /* Reset sendBuffer */
  memset(sendBuffer_, 0, sizeof(uint8_t) * BUFFER_SIZE);

  /* Convert message to char array */
  msg.toCharArray(sendBuffer_, msg.length() + 1);

  /* Send UDP packet and verify sending */
  if (receivedHostIP_) {
    udp_.beginPacket(parseIPString(hostIPStr_), portOutgoing_);
  } else {
    udp_.beginPacket(WifiConfig::wifiBroadcast, portOutgoing_);
  }

  uint8_t noBytesSent = udp_.write(sendBuffer_, msg.length() + 1);

  if(udp_.endPacket()) {
    return true;
  } else {
    return false;
  }
}

int32_t WifiCommunication::receiveUdpPacket() {
  /* Allow background tasks of WiFi stack to execute */
  yield();

  /* Parse UDP package */
  int noBytes = udp_.parsePacket();

  if ( noBytes ) {
    /* Read UDP package payload into char buffer */
    udp_.read(receiveBuffer_, noBytes); // read the packet into the buffer

    /* Create a string message from buffer */
    String msg;

    /* The received message is expected to contain a CSV string */
    for (int i = 0; i <= noBytes; i++){
      msg += String(receiveBuffer_[i]);
    }

    /* Store message in class variable */
    msg_ = msg;

    return noBytes;
  }

  return -1;
}

void WifiCommunication::processHostIP(String hostIP) {
  /* Assign IP to class variables */
  hostIP_     = parseIPString(hostIP);
  hostIPStr_  = String(hostIP);

  receivedHostIP_ = true;
  Serial.print("Host IP is assigned to "); Serial.println(hostIPStr_);
}

IPAddress WifiCommunication::parseIPString(String IP) {
  /* Parse serverIP, e.g. "192.168.1.22" */
  uint8_t ip[4];
  uint8_t del[5];

  del[0] = -1;
  del[1] = IP.indexOf('.');
  del[2] = IP.indexOf('.', del[1] + 1);
  del[3] = IP.indexOf('.', del[2] + 1);
  del[4] = IP.length();

  ip[0] = IP.substring(0, del[1]).toInt();
  //Serial.println(ip[0]);

  for (int i = 1; i < 4; i++) {
    ip[i] = IP.substring(del[i]+1, del[i+1]).toInt();
    //Serial.println(ip[i]);
  }

  return IPAddress(ip);
}
