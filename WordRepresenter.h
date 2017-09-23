/*
  WordRepresenter.h - Library for representing a letter with 2 stepper motors with a barrel.
  Created by Blindle, 25 August, 2017.
  Released into the public domain.
*/

#ifndef WordRepresenter_h
#define WordRepresenter_h

#include "Arduino.h"
#include "MultiplexorHandler.h"

class WordRepresenter
{
public:
  WordRepresenter(MultiplexorHandler &multiplexorHandler);
  void representWord(char *word);

private:
  int getMultiplexorData(const char *word, int side);
  int getNumberOfSidesPerMotor(char letter, int motorNumber);
  int getSides(int initialSide, int sideToReach);
  // int _latchPin;
  // int _clockPin;
  // int _dataPin;
  MultiplexorHandler _multiplexorHandler;
  int _delayBetweenSteps;
  const char *_lastWord;
};

#endif
