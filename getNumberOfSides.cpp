/*
  WordRepresenter.h - Library for representing a letter with 2 stepper motors with a barrel.
  Created by Blindle, 25 August, 2017.
  Released into the public domain.
*/

#include "WordRepresenter.h"

int WordRepresenter::getNumberOfSidesPerMotor(char letter, int motorNumber)
{
  int isFirstMotor = motorNumber == 0;
  switch (letter)
  {
  case '0':
    return isFirstMotor ? 0 : 0;
  case 'A':
    return isFirstMotor ? 1 : 0;
  case ',':
    return isFirstMotor ? 2 : 0;
  case 'B':
    return isFirstMotor ? 3 : 0;
  case '<':
    return isFirstMotor ? 4 : 0;
  case 'K':
    return isFirstMotor ? 5 : 0;
  case '>':
    return isFirstMotor ? 6 : 0;
  case 'L':
    return isFirstMotor ? 7 : 0;
  case '[':
    return isFirstMotor ? 0 : 1;
  case 'C':
    return isFirstMotor ? 1 : 1;
  case 'I':
    return isFirstMotor ? 2 : 1;
  case 'F':
    return isFirstMotor ? 3 : 1;
  case '/':
    return isFirstMotor ? 4 : 1;
  case 'M':
    return isFirstMotor ? 5 : 1;
  case 'S':
    return isFirstMotor ? 6 : 1;
  case 'P':
    return isFirstMotor ? 7 : 1;
  case ']':
    return isFirstMotor ? 0 : 2;
  case 'E':
    return isFirstMotor ? 1 : 2;
  case '{':
    return isFirstMotor ? 2 : 2;
  case 'H':
    return isFirstMotor ? 3 : 2;
  case '}':
    return isFirstMotor ? 4 : 2;
  case 'O':
    return isFirstMotor ? 5 : 2;
  case '!':
    return isFirstMotor ? 6 : 2;
  case 'R':
    return isFirstMotor ? 7 : 2;
  case '-':
    return isFirstMotor ? 0 : 3;
  case 'D':
    return isFirstMotor ? 1 : 3;
  case 'J':
    return isFirstMotor ? 2 : 3;
  case 'G':
    return isFirstMotor ? 3 : 3;
  case ';':
    return isFirstMotor ? 4 : 3;
  case 'N':
    return isFirstMotor ? 5 : 3;
  case 'T':
    return isFirstMotor ? 6 : 3;
  case 'Q':
    return isFirstMotor ? 7 : 3;
  case ':':
    return isFirstMotor ? 0 : 4;
  case '*':
    return isFirstMotor ? 1 : 4;
  case '"':
    return isFirstMotor ? 2 : 4;
  case '$':
    return isFirstMotor ? 3 : 4;
  case '_':
    return isFirstMotor ? 4 : 4;
  case 'U':
    return isFirstMotor ? 5 : 4;
  case '?':
    return isFirstMotor ? 6 : 4;
  case 'V':
    return isFirstMotor ? 7 : 4;
  case '%':
    return isFirstMotor ? 0 : 5;
  case '&':
    return isFirstMotor ? 1 : 5;
  case '(':
    return isFirstMotor ? 2 : 5;
  case ')':
    return isFirstMotor ? 3 : 5;
  case '\\':
    return isFirstMotor ? 4 : 5;
  case 'X':
    return isFirstMotor ? 5 : 5;
  case '\'':
    return isFirstMotor ? 6 : 5;
  case '1':
    return isFirstMotor ? 7 : 5;
  case '~':
    return isFirstMotor ? 0 : 6;
  case '5':
    return isFirstMotor ? 1 : 6;
  case '.':
    return isFirstMotor ? 2 : 6;
  case '6':
    return isFirstMotor ? 3 : 6;
  case '@':
    return isFirstMotor ? 4 : 6;
  case 'Z':
    return isFirstMotor ? 5 : 6;
  case '|':
    return isFirstMotor ? 6 : 6;
  case '3':
    return isFirstMotor ? 7 : 6;
  case '4':
    return isFirstMotor ? 0 : 7;
  case '^':
    return isFirstMotor ? 1 : 7;
  case 'W':
    return isFirstMotor ? 2 : 7;
  case '2':
    return isFirstMotor ? 3 : 7;
  case '#':
    return isFirstMotor ? 4 : 7;
  case 'Y':
    return isFirstMotor ? 5 : 7;
  case '+':
    return isFirstMotor ? 6 : 7;
  case '7':
    return isFirstMotor ? 7 : 7;
  default:
    return 0;
  }
  return 0;
}
