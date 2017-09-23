/*
  InputManager.h - Library for listening Serial Port and represent the word from it.
  Created by Blindle, 17 September, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "InputManager.h"

// MODES
const int SERIAL_PORT = 1;
const int MANUAL_MODE = 2;

// DELAYS
int DELAY_BETWEEN_WORDS = 2000;

InputManager::InputManager(int mode)
{
    _mode = mode;
    _hardcodedWordIndex = 0;
}

char *InputManager::getInput()
{
    switch (_mode)
    {
    case SERIAL_PORT:
        return listenSerialPort();
    case MANUAL_MODE:
    default:
        return getHardcodedWord();
    }
}

char *InputManager::listenSerialPort()
{
    char result[5];
    if (Serial.available())
    {
        Serial.readString().toCharArray(result, 5);
    }
    return result;
}

char *InputManager::getHardcodedWord()
{
    char *words[3] = {"AAAA", "CCCC", "BBBB"};
    delay(DELAY_BETWEEN_WORDS);
    return words[_hardcodedWordIndex++];
}
