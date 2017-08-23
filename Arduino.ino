#define LENGTH_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

// PINS_CONNECIONS
const int DIRECTION_PIN = 11; ////Pin that control the direction
const int LATCH_PIN = 10;  //Pin connected to ST_CP of 74HC595
const int CLOCK_PIN = 9; //Pin connected to SH_CP of 74HC595
const int DATA_PIN = 8;  ////Pin connected to DS of 74HC595

// DELAYS
const int DELAY_BETWEEN_WORDS = 2000;
const int DELAY_BETWEEN_MOTOR_STEPS = 100;

// MOTOR_DIRECTIONS
const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

// MOTORS_VARIABLES
const int NUMBER_OF_STEPS_PER_LOOP = 20;

const char EMPTY_CHARACTER = '@';
char lastWord[4] = {EMPTY_CHARACTER, EMPTY_CHARACTER, EMPTY_CHARACTER, EMPTY_CHARACTER};
char *words[4] = {"AAAA", "AAAA", "AAAA", "AAAA"};

// ARDUINO_LIFE_CYCLES
void setup()
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  Serial.begin(9600);
}

/* TODO: please create a library in order to remove a lot of code inside here,
  remember that this file has to manage only the life cycle of the arduino

  In my opinion, I will create 3 files more:
    - Configuration: manage all the pins, motors, and other configuration that we have.
    - Utils: store our helper functions, such as LENGHT_ARRAY, also I will love to have a function that can print more than one value.
    - [INSERT_LIBRARY_NAME_HERE]: will have only one public method --> representWord
        - Also it can have a constructor that will take the ammount of letters!
*/

void loop()
{
  int length = LENGTH_ARRAY(words);
  for (int i = 0; i < length; i++)
  {
    representWord(words[i]);
    delay(DELAY_BETWEEN_WORDS);
  }

  Serial.println("End of printing words!");
}

void representWord(char *word)
{
  Serial.print("Printing word: ");
  Serial.println(word);
  int length = strlen(word);
  for (int i = 0; i < length; i++)
  {
    representLetter(i, word[i]);
  }
}

void representLetter(int letterPosition, char letter)
{
  if (lastWord[letterPosition] != EMPTY_CHARACTER)
  {
    spinMotor(letterPosition, lastWord[letterPosition], LEFT_DIRECTION);
  }

  spinMotor(letterPosition, letter, RIGHT_DIRECTION);
  lastWord[letterPosition] = letter;
}

const int multiplexorRemoval[4][2] = {
    {0b01111111, 0b10111111},
    {0b11011111, 0b11101111},
    {0b01110111, 0b01111011},
    {0b01111101, 0b01111110},
};

void spinMotor(int letterPosition, char letter, int dir)
{
  digitalWrite(DIRECTION_PIN, dir);
  int *stepsPerMotor = getStepsPerMotor(letter);
  for (int i = 0; i < NUMBER_OF_STEPS_PER_LOOP; i++)
  {
    int multiplexorData = getMultiplexorData(letterPosition, stepsPerMotor, i);
    sendMultiplexorData(multiplexorData);
    delay(DELAY_BETWEEN_MOTOR_STEPS);
  }
}

int getMultiplexorData(int letterPosition, int *stepsPerMotor, int lap)
{
  int multiplexorData = 0b11111111;
  for (int j = 0; j < 2; j++)
  {
    if (stepsPerMotor[j] >= lap)
    {
      multiplexorData = multiplexorData & multiplexorRemoval[letterPosition][j];
    }
  }
  return multiplexorData;
}

void sendMultiplexorData(int data)
{
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(LATCH_PIN, HIGH);

  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  digitalWrite(LATCH_PIN, HIGH);
}

int *getStepsPerMotor(char letter)
{
  static int stepsPerMotor[2];
  switch (letter)
  {
  case 'A':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'B':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'C':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'D':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'E':
  {
    stepsPerMotor[0] = 6;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'F':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'G':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'H':
  {
    stepsPerMotor[0] = 10;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'I':
  {
    stepsPerMotor[0] = 8;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'J':
  {
    stepsPerMotor[0] = 8;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'K':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'L':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 0;
    break;
  }
  case 'M':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'N':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'O':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'P':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'Q':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'R':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 8;
    break;
  }
  case 'S':
  {
    stepsPerMotor[0] = 16;
    stepsPerMotor[1] = 12;
    break;
  }
  case 'T':
  {
    stepsPerMotor[0] = 16;
    stepsPerMotor[1] = 16;
    break;
  }
  case 'U':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 6;
    break;
  }
  case 'V':
  {
    stepsPerMotor[0] = 18;
    stepsPerMotor[1] = 6;
    break;
  }
  case 'W':
  {
    stepsPerMotor[0] = 8;
    stepsPerMotor[1] = 18;
    break;
  }
  case 'X':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 14;
    break;
  }
  case 'Y':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 18;
    break;
  }
  case 'Z':
  {
    stepsPerMotor[0] = 14;
    stepsPerMotor[1] = 10;
    break;
  }
  default:
  {
    stepsPerMotor[0] = 0;
    stepsPerMotor[1] = 0;
  }
  }
  return stepsPerMotor;
}
