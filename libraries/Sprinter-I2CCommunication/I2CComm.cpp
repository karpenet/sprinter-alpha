/*
 * I2CComm.cpp
 *
 *  Created on: 20-Mar-2018
 *      Author: karpenet
 */

#include "I2CComm.h"

I2CComm::I2CComm() {
	// TODO Auto-generated constructor stub

}

I2CComm::~I2CComm() {
	// TODO Auto-generated destructor stub
}

#ifdef ESP8266
void I2CComm::initialize(uint8_t sdaPin, uint8_t sclPin) {
  /* Set up mainboard as I2C master */
  Wire.begin(sdaPin, sclPin);
  _isMaster = true;

  /* Set up mainboard as I2C slave with parameterized address */
  /* NOTE: Slave mode is currently not supported by the ESP8266 Wire library */
}

#else

void I2CComm::initialize(uint8_t address) {
  if(!address) {
    /* Set up mainboard as I2C master */
    Wire.begin();
    _isMaster = true;
  } else {
    /* Set up mainboard as I2C slave with parameterized address */
    Wire.begin(address);
    _isMaster = false;

  }
}
#endif

void I2CComm::sendMessage(uint8_t msgType, float *data, uint8_t len, uint8_t address) {
  /* Initialize buffer for char array */
  uint8_t bufferSize = 1 + sizeof(float) * len;
  byte txBuffer[bufferSize];
  floatUnion tmp;

  /* Copy data into byte buffer */
  txBuffer[0] = msgType;
  for (int i = 0; i < len; i++) {
    tmp.fval = data[i];
    for (int j = 0; j < 4; j++) {
      txBuffer[1 + i*4 + j] = tmp.b[j];
    }
  }

  /* Transmit message */
  if(_isMaster) {
    /* Mainboard is set up as I2C master for communicating with I2C slave
     * receiver (by default message is sent to motor board with address 2)
     */
    Wire.beginTransmission(address);
    Wire.write(txBuffer, bufferSize);
    Wire.endTransmission();
  } else {
    /* Mainboard as I2C slave for debugging */
    Wire.write(txBuffer, bufferSize);
  }
}

void I2CComm::sendMessage(uint8_t msgType, float d1, float d2) {
  float data[2] = {d1, d2};
  sendMessage(msgType, data, 2);
}

void I2CComm::sendMessage(uint8_t msgType, float d1, float d2, float d3) {
  float data[3] = {d1, d2, d3};
  sendMessage(msgType, data, 3);
}

bool I2CComm::receiveMessage(I2CMessage* msgOut, uint8_t address) {
  uint8_t i = 0;

  /* Request 9 byte long message from slave with given address
   * uint8_t msgType ... 1 byte
   * float   data    ... 2 * 4 bytes
   */
  if(_isMaster) {
    Wire.requestFrom(address, (uint8_t)9);
  }

  /* Read message type */
  if(Wire.available()) {
    msgOut->msgType_ = Wire.read();
  } else {
    return false;
  }

  /* Read data values */
  while(Wire.available() && (i/4) < MAX_I2C_MSG_LENGTH){
    msgOut->data_[i/4].b[i%4] = Wire.read();
    i++;
  }

  if(i < 1) {
    return false;
  } else {
    return true;
  }
}
