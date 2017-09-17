#include "WordRepresenter.h"
#include "InputManager.h"

#define LENGTH_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

// PINS_CONNECIONS
int DIRECTION_PIN = 11; // Pin that controls the direction, connected to Pololu
int CLOCK_PIN = 10;     // Pin connected to SH_CP of 74HC595
int LATCH_PIN = 9;      // Pin connected to ST_CP of 74HC595
int DATA_PIN = 8;       // Pin connected to DS of 74HC595

// DELAYS
int DELAY_BETWEEN_MOTOR_STEPS = 1;

WordRepresenter wordRepresenter(LATCH_PIN, CLOCK_PIN, DATA_PIN, DELAY_BETWEEN_MOTOR_STEPS);
InputManager inputManager(1);
int selectedMode = SERIAL_PORT;

void setup()
{
  pinMode(DIRECTION_PIN, OUTPUT);
  digitalWrite(DIRECTION_PIN, HIGH);

  Serial.begin(9600);
}

void loop()
{
  char* word = inputManager.processInput();
  WordRepresenter.representWord(word);
}
