/*
  BarrelArranger.h - Library for manualy moving an specific to the right or to the left
  Created by Blindle, 22 Sept, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "BarrelArranger.h"
#include "MultiplexorHandler.h"

const char MOVE_BARREL_CHARACTER = '-';
const int STEPS_PER_MOVE = 100;
const int LEFT_DIRECTION = LOW;
const int RIGHT_DIRECTION = HIGH;

const int MULTIPLEXOR_DATA_BY_MOTOR_NUMBER[8] = {
    0b10000000,
    0b01000000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
};


BarrelArranger::BarrelArranger(MultiplexorHandler &multiplexorHandler, int directionPin) : _multiplexorHandler(multiplexorHandler)
{
  pinMode(directionPin, OUTPUT);
  digitalWrite(directionPin, RIGHT_DIRECTION);
    
  _directionPin = directionPin;
  _lastDirection = RIGHT_DIRECTION;
}

bool BarrelArranger::hasToMoveBarrel(char* word) {
    return word[0] == MOVE_BARREL_CHARACTER;
}

// expected shape of word when moving a barrel --> -D1 (D is the corresponding direction and 1 is the motor number)
void BarrelArranger::moveBarrel(char * word){
    int direction = word[1] == 'D' ? RIGHT_DIRECTION : LEFT_DIRECTION;
    int motorNumber = (int)word[2] - 48;

    moveMotor(motorNumber, direction);
}

void BarrelArranger::moveMotor(int motorNumber, int direction) {
    if(_lastDirection != direction) {
        digitalWrite(_directionPin, direction);
    }

    _lastDirection = direction;

    for (int side = 0; side < STEPS_PER_MOVE; side++) {
        _multiplexorHandler.sendMultiplexorData(MULTIPLEXOR_DATA_BY_MOTOR_NUMBER[motorNumber]);
    }

    if(direction == LEFT_DIRECTION) {
        digitalWrite(_directionPin, RIGHT_DIRECTION);
    }
}
