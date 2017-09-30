/*
  BarrelSpinner.h - Library for manualy moving an specific to the right or to the left
  Created by Blindle, 22 Sept, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "BarrelSpinner.h"
#include "MultiplexorHandler.h"

#define PARSE_TO_INT(character) ((int)character - 48)

const char MOVE_BARREL_CHARACTER = '-';
const int STEPS_PER_MOVE = 100;

const char LEFT_CHARACTER = 'I';
const char RIGHT_CHARACTER = 'D';

const int LEFT_DIRECTION = LOW;
const int RIGHT_DIRECTION = HIGH;

const int DEFAULT_DIRECTION = RIGHT_DIRECTION;

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

BarrelSpinner::BarrelSpinner(MultiplexorHandler &multiplexorHandler, int directionPin) : _multiplexorHandler(multiplexorHandler)
{
    _directionPin = directionPin;
    _lastDirection = DEFAULT_DIRECTION;
    
    pinMode(_directionPin, OUTPUT);
    digitalWrite(_directionPin, DEFAULT_DIRECTION);
}

bool BarrelSpinner::hasToMoveBarrel(String word)
{
    return word[0] == MOVE_BARREL_CHARACTER;
}

/* expected shape of word when moving a barrel --> -D1:
    * -: is the character that Raspberry send us in order to move a barrel.
    * D/I: is the direction that we want to spin, D is right and I is left.
    * [0, 1, 2, ..., 7]: is the motor number, this goes from 0 to 8.
*/
void BarrelSpinner::moveBarrel(String word)
{
    int direction = getDirection(word[1]);
    int motorNumber = PARSE_TO_INT(word[2]);

    moveMotor(motorNumber, direction);
    setDirection(DEFAULT_DIRECTION);
}

int BarrelSpinner::getDirection(char directionCharacter) {
    return directionCharacter == LEFT_CHARACTER ? LEFT_DIRECTION : RIGHT_DIRECTION;
}

void BarrelSpinner::moveMotor(int motorNumber, int direction)
{
    setDirection(direction);

    for (int side = 0; side < STEPS_PER_MOVE; side++)
    {
        _multiplexorHandler.sendMultiplexorData(MULTIPLEXOR_DATA_BY_MOTOR_NUMBER[motorNumber]);
    }
}

void BarrelSpinner::setDirection(int direction) {
    if (_lastDirection != direction)
    {
        digitalWrite(_directionPin, direction);
        _lastDirection = direction;
    }
}