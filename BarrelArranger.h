/*
  BarrelArranger.h - Library for manualy moving an specific to the right or to the left
  Created by Blindle, 22 Sept, 2017.
  Released into the public domain.
*/

#ifndef BarrelArranger_h
#define BarrelArranger_h

#include "Arduino.h"
#include "MultiplexorHandler.h"

class BarrelArranger
{
  public:
    BarrelArranger(MultiplexorHandler &_multiplexorHandler, int directionPin);
    void moveBarrel(char *word);
    bool hasToMoveBarrel(char *word);

  private:
    void moveMotor(int motorNumber, int direction);
    int getDirection(char directionCharacter);
    void restoreDirection(int direction);

    MultiplexorHandler _multiplexorHandler;
    int _directionPin;
    int _lastDirection;
};

#endif
