#include "WordRepresenter.h"
#include "InputManager.h"
#include "BarrelSpinner.h"
#include "MultiplexorHandler.h"

// PINS_CONNECIONS
int DIRECTION_PIN = 11; // Pin that controls the direction, connected to Pololu
int CLOCK_PIN = 10;     // Pin connected to SH_CP of 74HC595
int LATCH_PIN = 9;      // Pin connected to ST_CP of 74HC595
int DATA_PIN = 8;       // Pin connected to DS of 74HC595

const String END_OF_LINE = "z";
const String ARDUINO_LISTENING = "ARDUINO-LISTENING";

MultiplexorHandler multiplexorHandler(LATCH_PIN, CLOCK_PIN, DATA_PIN);
WordRepresenter wordRepresenter(multiplexorHandler);
BarrelSpinner barrelSpinner(multiplexorHandler, DIRECTION_PIN);
InputManager inputManager(InputManager::SERIAL_PORT_LISTENER);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String word = inputManager.getInput();
  sendMessageToSerial(word);

  if (BarrelSpinner::hasToMoveBarrel(word))
  {
    barrelSpinner.moveBarrel(word);
  } else {
    wordRepresenter.representWord(word);
  }

  sendMessageToSerial(ARDUINO_LISTENING);
}

void sendMessageToSerial(String word) {
  Serial.print(word + END_OF_LINE);
}
