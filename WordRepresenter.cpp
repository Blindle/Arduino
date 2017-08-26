/*
  WordRepresenter.h - Library for representing a letter with 2 stepper motors with a barrel.
  Created by Blindle, 25 August, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "WordRepresenter.h"

const int NUMBER_OF_STEPS_PER_LOOP = 2048;

const char EMPTY_CHARACTER = '@';

WordRepresenter::WordRepresenter(int latchPin, int clockPin, int dataPin, int delayBetweenSteps)
{
  	pinMode(latchPin, OUTPUT);
  	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	_latchPin = latchPin;
	_clockPin = clockPin;
	_dataPin = dataPin;
	_delayBetweenSteps = delayBetweenSteps;
	_lastWord = "   ";
}

void WordRepresenter::representWord(const char *word)
{
    Serial.print("Printing word: ");
    Serial.println(word);
    int multiplexorData;
    for (int step = 0; step < NUMBER_OF_STEPS_PER_LOOP; step++)
    {
      multiplexorData = getMultiplexorData(word, step);
      sendMultiplexorData(multiplexorData);
    }
    _lastWord = word;
}

const int multiplexorAdder[4][2] = {
  {0b10000000, 0b01000000},
  {0b00100000, 0b00010000},
  {0b00001000, 0b00000100},
  {0b00000010, 0b00000001},
};

int WordRepresenter::getMultiplexorData(const char *word, int step)
{
  int wordLength = strlen(word);
  int multiplexorData = 0;
  for (int i = 0; i < wordLength; i++)
  {
    int *stepsPerMotor = getStepsPerMotor(word[i]);
    // TODO: Please we need to take a look at this part of the program, it could have a lot of cases ...
    // int *stepsPerMotor = getStepsPerMotor(_lastWord[i]);

    // if(steps >= lastSteps) {
    //   if(steps * 102.4 >= (currentStep + lastSteps * 102.4)) {
    //     multiplexorData = multiplexorData | multiplexorAdder[i][0];
    //   } 
    // } else {
    //   if((lastSteps - steps) * 102.4 >= currentStep){
    //     multiplexorData = multiplexorData | multiplexorAdder[i][0];
    //   }
    // }
    
    if(stepsPerMotor[0] * 102.4 >= step)
      multiplexorData = multiplexorData | multiplexorAdder[i][0];
  
    if(stepsPerMotor[1] * 102.4 >= step)
      multiplexorData = multiplexorData | multiplexorAdder[i][1];
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

int * WordRepresenter::getStepsPerMotor(char letter)
{
  static int stepsPerMotor[2];
  switch (letter)
  {
  case 'A':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'B':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'C':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'D':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'E':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'F':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'G':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'H':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'I':
  {
    stepsPerMotor[0] = 8;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'J':
  {
    stepsPerMotor[0] = 8;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'K':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'L':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'M':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'N':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'O':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'P':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'Q':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'R':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'S':
  {
    stepsPerMotor[0] = 16;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'T':
  {
    stepsPerMotor[0] = 16;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'U':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 6;
    break;
  }
  case 'V':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 6;
    break;
  }
  case 'W':
  {
    stepsPerMotor[0] = 8;
    stepsPerMotor[1] = 18;
    break;
  }
  case 'X':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 14;
    break;
  }
  case 'Y':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 18;
    break;
  }
  case 'Z':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 10;
    break;
  }
  default:
  {
    stepsPerMotor[0] = 0;
    stepsPerMotor[1] = 0;
  }
  }
  return stepsPerMotor;
}

