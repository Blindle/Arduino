#include <HashMap.h>

// DEFINITION_VARIABLES
HashMap<char,int> lettersMap;

const int LATCH_PIN = 8; //Pin connected to ST_CP of 74HC595
const int CLOCK_PIN = 12; //Pin connected to SH_CP of 74HC595
const int DATA_PIN = 11; ////Pin connected to DS of 74HC595

const int DIRECTION_PIN = 4; ////Pin that control the direction
const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

// ARDUINO_LIFE_CYCLES
void setup() {
  //setup hashmap
  lettersMap = getAlphabetMap();

  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  hashMap.debug();
}

// void loop() {
//   digitalWrite(DIRECTION_PIN, RIGHT_DIRECTION);
//   digitalWrite(LATCH_PIN, LOW);
  
//   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, hashMap.getValueOf('A'));  
  
//   digitalWrite(LATCH_PIN, HIGH);
//   digitalWrite(LATCH_PIN, LOW);
  
//   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);  
  
//   digitalWrite(LATCH_PIN, HIGH);
//   delay(50);
// }

char letters[5] = {'A', 'E', 'S', 'Z', 'Y'};

void loop() {
  for(int i=0; i< 5; i++){
      representLetter(letters[i]);
      delay(100);
  }
} 

void representLetter(char letter) {
  digitalWrite(DIRECTION_PIN, RIGHT_DIRECTION);
  digitalWrite(LATCH_PIN, LOW);
  
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, letter);
  
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);
  
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);  
  
  digitalWrite(LATCH_PIN, HIGH);
  delay(50);
}

// HELPER_FUNCTIONS
HashMap<char,int> getAlphabetMap() {
  const byte HASH_SIZE = 25; //define the max size of the hashtable
  HashType<char,int> hashRawArray[HASH_SIZE]; //storage 
  const result = HashMap<char,int>( hashRawArray , HASH_SIZE ); //handles the storage [search,retrieve,insert]

  result[0]('A',  0b10000000);
  result[1]('B',  0b11000000);
  result[2]('C',  0b10010000);
  result[3]('D',  0b10011000);
  result[4]('E',  0b10001000);
  result[5]('F',  0b11010000);
  result[6]('G',  0b11011000);
  result[7]('H',  0b11001000);
  result[8]('I',  0b01001000);
  result[9]('J',  0b01011000);
  result[10]('K', 0b10100000);
  result[11]('L', 0b11100000);
  result[12]('M', 0b10110000);
  result[13]('N', 0b10111000);
  result[14]('O', 0b10101000);
  result[15]('P', 0b11110000);
  result[16]('Q', 0b11111000);
  result[17]('R', 0b11101000);
  result[18]('S', 0b01110000);
  result[19]('T', 0b01111000);
  result[20]('U', 0b10100100);
  result[21]('V', 0b11100100);
  result[22]('W', 0b01011100);
  result[23]('X', 0b10110100);
  result[24]('Y', 0b10111100);
  result[25]('Z', 0b10101100);

  return result;
}