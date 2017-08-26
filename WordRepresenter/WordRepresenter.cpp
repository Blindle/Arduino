/*
  WordRepresenter.h - Library for representing a letter with 2 stepper motors with a barrel.
  Created by Blindle, 25 August, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "WordRepresenter.h"

#define LENGTH_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

// PINS_CONNECIONS
const int DIRECTION_PIN = 11; ////Pin that control the direction

const int CLOCK_PIN = 10; //Pin connected to SH_CP of 74HC595
const int LATCH_PIN = 9;  //Pin connected to ST_CP of 74HC595
const int DATA_PIN = 8;       ////Pin connected to DS of 74HC595

// DELAYS
const int DELAY_BETWEEN_WORDS = 2000;
//const int DELAY_BETWEEN_MOTOR_STEPS = 100;
const int DELAY_BETWEEN_MOTOR_STEPS = 1;

// MOTOR_DIRECTIONS
const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

// MOTORS_VARIABLES
//const int NUMBER_OF_STEPS_PER_LOOP = 20;
const int NUMBER_OF_STEPS_PER_LOOP = 2048;

const char EMPTY_CHARACTER = '@';
char lastWord[4] = {EMPTY_CHARACTER, EMPTY_CHARACTER, EMPTY_CHARACTER, EMPTY_CHARACTER};
//char *words[4] = {"AAAA", "AAAA", "AAAA", "AAAA"};
char *words[1] = {"CCCC"};


WordRepresenter::WordRepresenter(int pin)
{
//   pinMode(pin, OUTPUT);
//   _pin = pin;
}

void WordRepresenter::representWord(char *word)
{
    Serial.print("Printing word: ");
    Serial.println(word);
    int multiplexorData = 0b11111111;
    for (int step = 0; step < NUMBER_OF_STEPS_PER_LOOP; step++)
    {
      int multiplexorData = getMultiplexorData(word, step); // when it returns 0 the motors wont spin
      // if(multiplexorData != 0)
        //Serial.println(multiplexorData);
        
      //sendMultiplexorData(multiplexorData);
      //sendMultiplexorData(0b00000001); // so by doing this, only one motor should spin
      // sendMultiplexorData(0b11110000); // so by doing this, only one motor should spin
       sendMultiplexorData(0b00000011); // so by doing this, only one motor should spin
      
  //    delay(DELAY_BETWEEN_MOTOR_STEPS);
  
    }
}

const int multiplexorAdder[4][2] = {
  {0b10000000, 0b01000000},
  {0b00100000, 0b00010000},
  {0b00001000, 0b00000100},
  {0b00000010, 0b00000001},
};

int getMultiplexorData(char *word, int step)
{
  int wordLength = strlen(word);
  int multiplexorData = 0;
  for (int i = 0; i < wordLength; i++)
  {
    int *stepsPerMotor = getStepsPerMotor(word[i]);
    
    if(stepsPerMotor[0] * 102.4 >= step) 
      multiplexorData = multiplexorData | multiplexorAdder[i][0];
  
    if(stepsPerMotor[1] * 102.4 >= step) 
      multiplexorData = multiplexorData | multiplexorAdder[i][1];
  }

  return multiplexorData;
}

void sendMultiplexorData(int data)
{
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, data);   
  digitalWrite(LATCH_PIN, HIGH);
  delay(10);

  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0);   
  digitalWrite(LATCH_PIN, HIGH);
  delay(10);
}

int *getStepsPerMotor(char letter)
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

