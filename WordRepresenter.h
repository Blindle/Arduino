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
  void representWord(String word);

private:
  int getMultiplexorData(String word, int side);
  int getNumberOfSidesPerMotor(char letter, int motorNumber);
  int getSides(int initialSide, int sideToReach);

  MultiplexorHandler _multiplexorHandler;
  int _delayBetweenSteps;
  String _lastWord;
};

#endif
