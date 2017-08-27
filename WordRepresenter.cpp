/*
  WordRepresenter.h - Library for representing a letter with 2 stepper motors with a barrel.
  Created by Blindle, 25 August, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "WordRepresenter.h"

const int NUMBER_OF_STEPS_PER_LOOP = 2048;
const int NUMBER_OF_SIDES = 8;
const int NUMBER_OF_STEPS_PER_SIDE = NUMBER_OF_STEPS_PER_LOOP / NUMBER_OF_SIDES; //256
const int MOTORS_PER_LETTER = 2;

WordRepresenter::WordRepresenter(int latchPin, int clockPin, int dataPin, int delayBetweenSteps)
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  _latchPin = latchPin;
  _clockPin = clockPin;
  _dataPin = dataPin;
  _delayBetweenSteps = delayBetweenSteps;
  _lastWord = "    ";
}

void WordRepresenter::representWord(char *word)
{
  int multiplexorData;
  for (int side = 0; side < NUMBER_OF_SIDES; side++)
  {
    multiplexorData = getMultiplexorData(word, side);

    if (multiplexorData == 0)
      break; //in case that we dont have to move the steppers, we will cut the for.

    for (int step = 0; step < NUMBER_OF_STEPS_PER_SIDE; step++)
    {
      sendMultiplexorData(multiplexorData);
    }
  }
  strcpy(_lastWord, word);
}

const int multiplexorAdder[4][2] = {
    {0b10000000, 0b01000000},
    {0b00100000, 0b00010000},
    {0b00001000, 0b00000100},
    {0b00000010, 0b00000001},
};

int WordRepresenter::getSides(int initialSide, int sideToReach)
{
  return (NUMBER_OF_SIDES - initialSide + sideToReach) % NUMBER_OF_SIDES;
}

int WordRepresenter::getMultiplexorData(const char *word, int side)
{
  int wordLength = strlen(word);
  int multiplexorData = 0;
  for (int i = 0; i < wordLength; i++)
  {
    char letter = word[i];
    char lastLetter = _lastWord[i];

    for (int motorNumber = 0; motorNumber < MOTORS_PER_LETTER; motorNumber++)
    {
      int sidesMotor = getNumberOfSidesPerMotor(letter, motorNumber);
      int lastSidesMotor = getNumberOfSidesPerMotor(lastLetter, motorNumber);
      int sidesToTravel = getSides(lastSidesMotor, sidesMotor);

      if (sidesToTravel > side)
      {
        multiplexorData = multiplexorData | multiplexorAdder[i][motorNumber];
      }
    }
  }

  return multiplexorData;
}

void WordRepresenter::sendMultiplexorData(int data)
{
  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, LSBFIRST, data);
  digitalWrite(_latchPin, HIGH);
  delay(_delayBetweenSteps);

  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, LSBFIRST, 0);
  digitalWrite(_latchPin, HIGH);
  delay(_delayBetweenSteps);
}

int WordRepresenter::getNumberOfSidesPerMotor(char letter, int motorNumber)
{
  int isFirstMotor = motorNumber == 0;
  switch (letter)
  {
  case 'A':
    return isFirstMotor ? 1 : 0;
  case 'B':
    return isFirstMotor ? 3 : 0;
  case 'C':
    return isFirstMotor ? 1 : 1;
  case 'D':
    return isFirstMotor ? 1 : 3;
  case 'E':
    return isFirstMotor ? 1 : 2;
  case 'F':
    return isFirstMotor ? 3 : 1;
  default:
    return 0;
  }
  return 0;
}
