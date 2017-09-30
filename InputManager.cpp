/*
  InputManager.h - Library for listening Serial Port and represent the word from it.
  Created by Blindle, 17 September, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "InputManager.h"

// MODES
const int InputManager::SERIAL_PORT_LISTENER = 1;
const int InputManager::MANUAL_MODE = 2;

// CONSTANTS STRINGS
const String INITIAL_VALUE = "     ";
const String HARDCODES_WORDS[3] = {"AAAA", "BBBB", "CCCC"};

// DELAYS
const int DELAY_BETWEEN_WORDS = 2000;
const int POOLING_SERIAL_DELAY = 10;

InputManager::InputManager(int mode)
{
    _mode = mode;
    _hardcodedWordIndex = 0;
}

String InputManager::getInput()
{
    switch (_mode)
    {
    case SERIAL_PORT_LISTENER:
        return listenSerialPort();
    case MANUAL_MODE:
    default:
        return getHardcodedWord();
    }
}

String InputManager::listenSerialPort()
{
    String result = INITIAL_VALUE;
    while (result == INITIAL_VALUE)
    {
        if (Serial.available())
        {
            result = Serial.readString();
        }
        delay(POOLING_SERIAL_DELAY);
    }
    return result;
}

String InputManager::getHardcodedWord()
{
    delay(DELAY_BETWEEN_WORDS);
    return HARDCODES_WORDS[_hardcodedWordIndex++ % 3];
}
