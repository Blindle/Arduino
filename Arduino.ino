#include "WordRepresenter.h"

#define LENGTH_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

// PINS_CONNECIONS
int DIRECTION_PIN = 11; // Pin that controls the direction, connected to Pololu
int CLOCK_PIN = 10;     // Pin connected to SH_CP of 74HC595
int LATCH_PIN = 9;      // Pin connected to ST_CP of 74HC595
int DATA_PIN = 8;       // Pin connected to DS of 74HC595

// DELAYS
int DELAY_BETWEEN_WORDS = 2000;
int DELAY_BETWEEN_MOTOR_STEPS = 1;

// MODES
const int ARDUINO_MODE = 1;
const int MANUAL_MODE = 2;
char *words[3] = {"AAAA", "CCCC", "BBBB"};

WordRepresenter wordRepresenter(LATCH_PIN, CLOCK_PIN, DATA_PIN, DELAY_BETWEEN_MOTOR_STEPS);
int selectedMode;

void setup()
{
  pinMode(DIRECTION_PIN, OUTPUT);
  digitalWrite(DIRECTION_PIN, HIGH);

  Serial.begin(9600);
  selectedMode = ARDUINO_MODE;
}

void loop()
{
  switch (selectedMode)
  {
  case ARDUINO_MODE:
    return listenRaspberry();
  case MANUAL_MODE:
  default:
    return representHardcodedWords();
  }
}

void listenRaspberry()
{

  if (Serial.available())
  {
    char wordChar[5];
    Serial.readString().toCharArray(wordChar, 5);

    Serial.println(wordChar);
    wordRepresenter.representWord(wordChar);
    delay(DELAY_BETWEEN_WORDS);
  }
}

void representHardcodedWords()
{
  int length = LENGTH_ARRAY(words);
  for (int i = 0; i < length; i++)
  {
    wordRepresenter.representWord(words[i]);
    delay(DELAY_BETWEEN_WORDS);
  }

  Serial.println("End of printing words!");
}
