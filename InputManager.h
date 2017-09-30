/*
  InputManager.h - Library for listening Serial Port and represent the word from it.
  Created by Blindle, 17 September, 2017.
  Released into the public domain.
*/

#ifndef InputManager_h
#define InputManager_h

#include "InputManager.h"

class InputManager
{
public:
  static const int SERIAL_PORT_LISTENER;
  static const int MANUAL_MODE;
  InputManager(int mode);
  String getInput();

private:
  String listenSerialPort();
  String getHardcodedWord();
  int _mode;
  int _hardcodedWordIndex;
};

#endif
