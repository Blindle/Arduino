// #include "WordRepresenter.h"
// #include "InputManager.h"
// #include "BarrelArranger.h"
#include "MultiplexorHandler.h"

#define LENGTH_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

// PINS_CONNECIONS
int DIRECTION_PIN = 11; // Pin that controls the direction, connected to Pololu
int CLOCK_PIN = 10;     // Pin connected to SH_CP of 74HC595
int LATCH_PIN = 9;      // Pin connected to ST_CP of 74HC595
int DATA_PIN = 8;       // Pin connected to DS of 74HC595

MultiplexorHandler multiplexorHandler(LATCH_PIN, CLOCK_PIN, DATA_PIN);
// WordRepresenter wordRepresenter(multiplexorHandler);
// BarrelArranger barrelArranger(multiplexorHandler, DIRECTION_PIN);
// InputManager inputManager(1);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // char *word = inputManager.getInput();

  // if (barrelArranger.hasToMoveBarrel(word))
  // {
  //   barrelArranger.moveBarrel(word);
  // }
  // else
  // {
  //   wordRepresenter.representWord(word);
  // }
}
