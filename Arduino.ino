const int DIRECTION_PIN = 11; ////Pin that control the direction
const int LATCH_PIN = 10;  //Pin connected to ST_CP of 74HC595
const int CLOCK_PIN = 9; //Pin connected to SH_CP of 74HC595
const int DATA_PIN = 8;  ////Pin connected to DS of 74HC595

const int RIGHT_DIRECTION = HIGH;
const int LEFT_DIRECTION = LOW;

const int DELAY_BETWEEN_LETTERS = 1000;
const byte BLINK_ALL_LED = 0b11111111;

// ARDUINO_LIFE_CYCLES
void setup()
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(DIRECTION_PIN, RIGHT_DIRECTION);
  for (int j = 0; j < 20; j++)
  {
    sendDataToMultiplexors(BLINK_ALL_LED, BLINK_ALL_LED, 10);
    sendDataToMultiplexors(0, 0, 10);
  }
  delay(DELAY_BETWEEN_LETTERS);
}

void sendDataToMultiplexors(byte first, byte second, int delayTime){
    digitalWrite(LATCH_PIN, 0);
    shiftOut(DATA_PIN, CLOCK_PIN, first);
    shiftOut(DATA_PIN, CLOCK_PIN, second);
    digitalWrite(LATCH_PIN, 1);
    delay(delayTime);
}

// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut)
{
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i = 0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i = 7; i >= 0; i--)
  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if (myDataOut & (1 << i))
    {
      pinState = 1;
    }
    else
    {
      pinState = 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}