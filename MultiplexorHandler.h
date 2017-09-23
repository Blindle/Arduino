/*
  MultiplexorHandler.h - Library for sending information to Multiplexor
  Created by Blindle, 22 Sept, 2017.
  Released into the public domain.
*/

#ifndef MultiplexorHandler_h
#define MultiplexorHandler_h

#include "MultiplexorHandler.h"

class MultiplexorHandler
{
  public:
    MultiplexorHandler(int latchPin, int clockPin, int dataPin);
    void sendMultiplexorData(int data);

  private:
    int _latchPin;
    int _clockPin;
    int _dataPin;
};

#endif
