#include <WordRepresenter.h>

#define LENGTH_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

// PINS_CONNECIONS
int DIRECTION_PIN = 11; ////Pin that control the direction
int CLOCK_PIN = 10; //Pin connected to SH_CP of 74HC595
int LATCH_PIN = 9;  //Pin connected to ST_CP of 74HC595
int DATA_PIN = 8;       //Pin connected to DS of 74HC595

// DELAYS
int DELAY_BETWEEN_WORDS = 2000;
int DELAY_BETWEEN_MOTOR_STEPS = 1;

const char *words[1] = {"CCCC"};

WordRepresenter wordRepresenter(LATCH_PIN, CLOCK_PIN, DATA_PIN, DELAY_BETWEEN_MOTOR_STEPS);

// ARDUINO_LIFE_CYCLES
void setup()
{
  pinMode(DIRECTION_PIN, OUTPUT);
  digitalWrite(DIRECTION_PIN, HIGH);
  
  Serial.begin(9600);
}

void loop()
{
  int length = LENGTH_ARRAY(words);
  for (int i = 0; i < length; i++)
  {
    wordRepresenter.representWord(words[i]);
    delay(DELAY_BETWEEN_WORDS);
  }

  Serial.println("End of printing words!");
}