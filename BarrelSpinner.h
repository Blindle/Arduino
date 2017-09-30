/*
  BarrelSpinner.h - Library for manualy moving an specific stepper motor to the right or to the left
  Created by Blindle, 22 Sept, 2017.
  Released into the public domain.
*/

#ifndef BarrelSpinner_h
#define BarrelSpinner_h

#include "Arduino.h"
#include "MultiplexorHandler.h"

class BarrelSpinner
{
  public:
    BarrelSpinner(MultiplexorHandler &_multiplexorHandler, int directionPin);
    void moveBarrel(String word);
    static bool hasToMoveBarrel(String word);

  private:
    void moveMotor(int motorNumber, int direction);
    int getDirection(char directionCharacter);
    void setDirection(int direction);

    MultiplexorHandler _multiplexorHandler;
    int _directionPin;
    int _lastDirection;
};

#endif
