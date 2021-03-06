/*
  InputManager.h - Library for listening Serial Port and represent the word from it.
  Created by Blindle, 17 September, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "MultiplexorHandler.h"

int DELAY_BETWEEN_MOTOR_STEPS = 1;
int NO_DATA = 0;

MultiplexorHandler::MultiplexorHandler(int latchPin, int clockPin, int dataPin)
{
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    _latchPin = latchPin;
    _clockPin = clockPin;
    _dataPin = dataPin;
}

void MultiplexorHandler::sendMultiplexorData(int data)
{
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, LSBFIRST, data);
    digitalWrite(_latchPin, HIGH);
    delay(DELAY_BETWEEN_MOTOR_STEPS);

    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, LSBFIRST, NO_DATA);
    digitalWrite(_latchPin, HIGH);
    delay(DELAY_BETWEEN_MOTOR_STEPS);
}
