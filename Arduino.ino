const int LATCH_PIN = 8; //Pin connected to ST_CP of 74HC595
const int CLOCK_PIN = 12; //Pin connected to SH_CP of 74HC595
const int DATA_PIN = 11; ////Pin connected to DS of 74HC595

const int DIRECTION_PIN = 4; ////Pin that control the direction
const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

const int DELAY_BETWEEN_LETTERS = 2000;
const char letters[5] = {'A', 'A', 'A', 'A', 'A'};
const int NUMBER_OF_STEPS_PER_LOOP = 20;
const char EMPTY_CHARACTER = '@';

// ARDUINO_LIFE_CYCLES
void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  Serial.begin(9600);
}

char lastCharacter = EMPTY_CHARACTER;

void loop() {
  for(int i=0; i < 5; i++){
    if(lastCharacter != EMPTY_CHARACTER) {
      representLetter(lastCharacter, LEFT_DIRECTION);  
    }
    
    representLetter('A', RIGHT_DIRECTION);
    delay(DELAY_BETWEEN_LETTERS);  
  }
}

void representLetter(char letter, int dir) {
  digitalWrite(DIRECTION_PIN, dir);
  
  lastCharacter = letter;
  int * stepsPerMotor = getStepsPerMotor(letter);
  int spinningMotor =  0b11111111;
  for(int i=0; i < NUMBER_OF_STEPS_PER_LOOP; i++){
    digitalWrite(LATCH_PIN, LOW);
    
    if (stepsPerMotor[0] == i) {
      spinningMotor = spinningMotor & 0b01111111;
    }
    if (stepsPerMotor[1] == i) {
      spinningMotor = spinningMotor & 0b10111111;
    }
    
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, spinningMotor);
    digitalWrite(LATCH_PIN, HIGH);

    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
    digitalWrite(LATCH_PIN, HIGH);
    delay(10);
  }
}

int stepsPerMotor[2];
int * getStepsPerMotor(char letter) {
  switch(letter) {
    case 'A': {
      stepsPerMotor[0] = 6;
      stepsPerMotor[1] = 0;
      break;
    }
    case 'B': {
      stepsPerMotor[0] = 10;
      stepsPerMotor[1] = 0;
      break;
    }
    case 'C': {
      stepsPerMotor[0] = 6;
      stepsPerMotor[1] = 12;
      break;
    }
    case 'D': {
      stepsPerMotor[0] = 6;
      stepsPerMotor[1] = 16;
      break;
    }
    case 'E': {
      stepsPerMotor[0] = 6;
      stepsPerMotor[1] = 8;
      break;
    }
    case 'F': {
      stepsPerMotor[0] = 10;
      stepsPerMotor[1] = 12;
      break;
    }
    case 'G': {
      stepsPerMotor[0] = 10;
      stepsPerMotor[1] = 16;
      break;
    }
    case 'H': {
      stepsPerMotor[0] = 10;
      stepsPerMotor[1] = 8;
      break;
    }
    case 'I': {
      stepsPerMotor[0] = 8;
      stepsPerMotor[1] = 12;
      break;
    }
    case 'J': {
      stepsPerMotor[0] = 8;
      stepsPerMotor[1] = 16;
      break;
    }
    case 'K': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 0;
      break;
    }
    case 'L': {
      stepsPerMotor[0] = 18;
      stepsPerMotor[1] = 0;
      break;
    }
    case 'M': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 12;
      break;
    }
    case 'N': {
      stepsPerMotor[0] = 18;
      stepsPerMotor[1] = 16;
      break;
    }
    case 'O': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 8;
      break;
    }
    case 'P': {
      stepsPerMotor[0] = 18;
      stepsPerMotor[1] = 12;
      break;
    }
    case 'Q': {
      stepsPerMotor[0] = 18;
      stepsPerMotor[1] = 16;
      break;
    }
    case 'R': {
      stepsPerMotor[0] = 18;
      stepsPerMotor[1] = 8;
      break;
    }
    case 'S': {
      stepsPerMotor[0] = 16;
      stepsPerMotor[1] = 12;
      break;
    }
    case 'T': {
      stepsPerMotor[0] = 16;
      stepsPerMotor[1] = 16;
      break;
    }
    case 'U': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 6;
      break;
    }
    case 'V': {
      stepsPerMotor[0] = 18;
      stepsPerMotor[1] = 6;
      break;
    }
    case 'W': {
      stepsPerMotor[0] = 8;
      stepsPerMotor[1] = 18;
      break;
    }
    case 'X': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 14;
      break;
    }
    case 'Y': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 18;
      break;
    }
    case 'Z': {
      stepsPerMotor[0] = 14;
      stepsPerMotor[1] = 10;
      break;
    }
    default: {
      stepsPerMotor[0] = 0;
      stepsPerMotor[1] = 0;
    }
  }
  return stepsPerMotor;
}
