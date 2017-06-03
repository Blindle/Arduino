#include <HashMap.h>

// DEFINITION_VARIABLES
const byte HASH_SIZE = 24; //define the max size of the hashtable
HashType<char,int> hashRawArray[HASH_SIZE]; //storage 
HashMap<char,int> lettersMap = HashMap<char,int>( hashRawArray , HASH_SIZE ); //handles the storage [search,retrieve,insert]

const int latchPin = 8; //Pin connected to ST_CP of 74HC595
const int clockPin = 12; //Pin connected to SH_CP of 74HC595
const int dataPin = 11; ////Pin connected to DS of 74HC595

const int dirPin = 4; ////Pin that control the direction
const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

// ARDUINO_LIFE_CYCLES
void setup() {
  //setup hashmap
  setupLettersMap();

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(dirPin,OUTPUT);
  hashMap.debug();
}

void loop() {
  digitalWrite(dirPin, RIGHT_DIRECTION);
  digitalWrite(latchPin, LOW);
  
  shiftOut(dataPin, clockPin, MSBFIRST, hashMap.getValueOf('a'));  
  
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  
  shiftOut(dataPin, clockPin, MSBFIRST, 0);  
  
  digitalWrite(latchPin, HIGH);
  delay(50);
}

// HELPER_FUNCTIONS
void setupLettersMap() {
  lettersMap[0]('a', 0b10000000);
  lettersMap[1]('b', 0b11000000);
  // complete with the all the letters that are missing ..
}