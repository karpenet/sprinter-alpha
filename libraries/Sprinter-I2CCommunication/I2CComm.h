/*
 * I2CComm.h
 *
 *  Created on: 20-Mar-2018
 *      Author: karpenet
 */

#ifndef I2CCOMM_H_
#define I2CCOMM_H_
#include <Arduino.h>
#include <Wire.h>

#include "includes/I2CMessages.h"

class I2CComm {
public:
	I2CComm();
	~I2CComm();

#ifdef ESP8266
      void initialize(uint8_t sdaPin, uint8_t sclPin);
#else
      void initialize(uint8_t address = 0);
#endif

      void sendMessage(uint8_t msgType, float d1, float d2);
      void sendMessage(uint8_t msgType, float d1, float d2, float d3);
      void sendMessage(uint8_t msgType, float *data, uint8_t len, uint8_t address = 2);
      void sendMessage(I2CMessage msg, uint8_t address = 2);
      bool receiveMessage(I2CMessage* msgOut, uint8_t address = 2);

      bool isMaster() {
              return _isMaster;
            }

          //--------------------------------------------------------------------------
          // Private Member Variables
          //--------------------------------------------------------------------------
          private:
            bool _isMaster;
};

#endif /* I2CCOMM_H_ */
