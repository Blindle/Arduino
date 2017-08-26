/*
  WordRepresenter.h - Library for representing a letter with 2 stepper motors with a barrel.
  Created by Blindle, 25 August, 2017.
  Released into the public domain.
*/

#ifndef WordRepresenter_h
#define WordRepresenter_h

#include "Arduino.h"

class WordRepresenter
{
  public:
    WordRepresenter(int pin);
    void representWord(char *word);
  private:
    int _pin;
};

#endif

