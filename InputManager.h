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
  InputManager(int mode);
  void getInput();

private:
    int _mode;
};

#endif
