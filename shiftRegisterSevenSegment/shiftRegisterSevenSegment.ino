#include <Keypad.h>
#include <ctype.h>

int dataPin = 11;
int clockPin = 12;
int latchPin = 8;
byte data = 0;

int a = 2; // CHECK
int b = 1; // CHECK
int c = 6; // CHECK
int d = 7; // CHECK
int e = 0; // CHECK
int f = 3; // CHECK
int g = 4; // CHECK 
int dp = 5; // CHECK

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 9, 10}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    clearDisplay();
    writeToSegmentDisplay(customKey);
  }
}

void writeToSegmentDisplay(char input) {
  switch (input) {
    case '1':
      shiftWrite(b,1);
      shiftWrite(c,1);
      break;
    case '2':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(g,1);
      shiftWrite(e,1);
      shiftWrite(d,1);
      break;
    case '3':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(g,1);
      shiftWrite(c,1);
      shiftWrite(d,1);
      break;
    case '4':
      shiftWrite(f,1);
      shiftWrite(g,1);
      shiftWrite(b,1);
      shiftWrite(c,1);
      break;
    case '5':
      shiftWrite(a,1);
      shiftWrite(f,1);
      shiftWrite(g,1);
      shiftWrite(c,1);
      shiftWrite(d,1);
      break;
    case '6':
      shiftWrite(a,1);
      shiftWrite(f,1);
      shiftWrite(g,1);
      shiftWrite(c,1);
      shiftWrite(e,1);
      shiftWrite(d,1);
      break;
    case '7':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(c,1);
      break;
    case '8':
    case 'B':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(c,1);
      shiftWrite(d,1);
      shiftWrite(e,1);
      shiftWrite(f,1);
      shiftWrite(g,1);
      break;
    case '9':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(c,1);
      shiftWrite(d,1);
      shiftWrite(f,1);
      shiftWrite(g,1);
      break;
    case '0':
    case 'D':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(c,1);
      shiftWrite(d,1);
      shiftWrite(e,1);
      shiftWrite(f,1);
      break;
    case 'A':
      shiftWrite(a,1);
      shiftWrite(b,1);
      shiftWrite(c,1);
      shiftWrite(e,1);
      shiftWrite(f,1);
      shiftWrite(g,1);
      break;
    case 'C':
      shiftWrite(a,1);
      shiftWrite(d,1);
      shiftWrite(e,1);
      shiftWrite(f,1);
      break;
    default:
      shiftWrite(dp,1);
  }
}

void clearDisplay() {
  shiftWrite(a,0);
  shiftWrite(b,0);
  shiftWrite(c,0);
  shiftWrite(d,0);
  shiftWrite(e,0);
  shiftWrite(f,0);
  shiftWrite(g,0);
  shiftWrite(dp,0);
}

void shiftWrite(int desiredPin, boolean desiredState) {
  bitWrite(data,desiredPin,desiredState);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}