//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

const int dirPin = 4;

const int right = HIGH;
const int left = LOW;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(dirPin,OUTPUT);
}

void loop() {
  digitalWrite(dirPin, right);
  digitalWrite(latchPin, LOW);
  
  shiftOut(dataPin, clockPin, MSBFIRST, 3);  
  
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  
  shiftOut(dataPin, clockPin, MSBFIRST, 0);  
  
  digitalWrite(latchPin, HIGH);
  delay(50);
}
