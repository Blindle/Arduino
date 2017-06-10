const int LATCH_PIN = 8; //Pin connected to ST_CP of 74HC595
const int CLOCK_PIN = 12; //Pin connected to SH_CP of 74HC595
const int DATA_PIN = 11; ////Pin connected to DS of 74HC595

const int DIRECTION_PIN = 4; ////Pin that control the direction
const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

const int DELAY_BETWEEN_LETTERS = 1000;
const char letters[5] = {'A', 'E', 'S', 'Z', 'Y'};

// ARDUINO_LIFE_CYCLES
void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
}

void loop() {
  digitalWrite(DIRECTION_PIN, RIGHT_DIRECTION); // Set direction of the 
  int arrayLenght = sizeof(letters)/sizeof(letters[0]);
  for(int i=0; i< arrayLenght; i++){
      representLetter(letters[i], 3);
      delay(DELAY_BETWEEN_LETTERS);
  }
} 

void representLetter(char letter, int numberOfLoops) {
  for(int i=0; i < numberOfLoops * 20; i++){
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, getCodeOfLetter(letter));
    digitalWrite(LATCH_PIN, HIGH);

    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
    digitalWrite(LATCH_PIN, HIGH);
    delay(10);   
  }
}

int getCodeOfLetter(char letter) {
  switch(letter) {
    case 'A': return 0b10000000;
    case 'B': return 0b11000000;
    case 'C': return 0b10010000;
    case 'D': return 0b10011000;
    case 'E': return 0b10001000;
    case 'F': return 0b11010000;
    case 'G': return 0b11011000;
    case 'H': return 0b11001000;
    case 'I': return 0b01001000;
    case 'J': return 0b01011000;
    case 'K': return 0b10100000;
    case 'L': return 0b11100000;
    case 'M': return 0b10110000;
    case 'N': return 0b10111000;
    case 'O': return 0b10101000;
    case 'P': return 0b11110000;
    case 'Q': return 0b11111000;
    case 'R': return 0b11101000;
    case 'S': return 0b01110000;
    case 'T': return 0b01111000;
    case 'U': return 0b10100100;
    case 'V': return 0b11100100;
    case 'W': return 0b01011100;
    case 'X': return 0b10110100;
    case 'Y': return 0b10111100;
    case 'Z': return 0b10101100;
    default: return 0;
  }
}




