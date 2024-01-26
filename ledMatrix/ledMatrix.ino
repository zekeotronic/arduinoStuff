#include "LedControl.h"

int dataPin = 12;
int clkPin = 11;
int csPin = 10;



LedControl lc=LedControl(dataPin, clkPin, csPin, 1);


unsigned long delaytime=100;


void setup() {
 
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,1);
  /* and clear the display */
  lc.clearDisplay(0);
}

void setDisplay(byte row1, byte row2, byte row3, byte row4, byte row5, byte row6, byte row7, byte row8) {
  lc.setRow(0, 0, row1);
  lc.setRow(0, 1, row2);
  lc.setRow(0, 2, row3);
  lc.setRow(0, 3, row4);
  lc.setRow(0, 4, row5);
  lc.setRow(0, 5, row6);
  lc.setRow(0, 6, row7);
  lc.setRow(0, 7, row8);
}

void writeFunnyFace() {
  setDisplay(B00000000,B01100110,B01100110,B00000000,B00011000,B00011000,B10000001,B01111110);
}

void writeSadFace() {
  setDisplay(B00000000,B01100110,B01100110,B00000000,B00011000,B00011000,B01111110,B10000001);
}

void writeSkull() {
  setDisplay(B01111100,B11111110,B10010010,B10111010,B11101110,B00111000,B00101000,B00101000);
}

void writeDino() {
  setDisplay(B01111000, B10101000, B11111000, B00111000, B01111010, B00111010, B00111100, B00101000);
}
void writeCoffee() {
  setDisplay(B11111100, B11111111, B11111101, B11111101, B11111111, B11111110, B01111100, B00000000);
}

void writeBell() {
  setDisplay(B00000000, B00011000, B00111100, B00111100, B00111100, B00111100, B01111110, B00011000);
}

void writeHeart() {
  setDisplay(B00000000, B01101100, B11111110, B11111110, B01111100, B00111000, B00010000, B00000000);
}

void clearScreen() {
  setDisplay(B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000);
}

void writeChar(char letter) {
  switch (letter) {
    case 'a':
    case 'A':
      setDisplay(B01111110,B11111111,B11100111,B11100111,B11111111,B11111111,B11100111,B11100111);
      break;
    case 'b':
    case 'B':
      setDisplay(B11111110,B11111111,B11100111,B11111110,B11111110,B11100111,B11111111,B11111110);
      break;
    case 'c':
    case 'C':
      setDisplay(B01111110,B11111111,B11100111,B11100000,B11100000,B11100111,B11111111,B01111110);
      break;
    case 'd':
    case 'D':
      setDisplay(B11111110,B11111111,B11100111,B11100111,B11100111,B11100111,B11111111,B11111110);
      break;
    case 'e':
    case 'E':
      setDisplay(B11111111,B11111111,B11100000,B11111100,B11111100,B11100000,B11111111,B11111111);
      break;
    case 'f':
    case 'F':
      setDisplay(B11111111,B11111111,B11100000,B11111100,B11111100,B11100000,B11100000,B11100000);
      break;
    case 'g':
    case 'G':
      setDisplay(B01111110,B11111111,B11100111,B11100000,B11101111,B11100111,B11111111,B01111110);
      break;
    case 'h':
    case 'H':
      setDisplay(B11100111,B11100111,B11100111,B11111111,B11111111,B11100111,B11100111,B11100111);
      break;
    case 'i':
    case 'I':
      setDisplay(B00011100,B00011100,B00011100,B00011100,B00011100,B00011100,B00011100,B00011100);
      break;
    case 'j':
    case 'J':
      setDisplay(B00011100,B00011100,B00011100,B00011100,B00011100,B00011100,B11111100,B11111000);
      break;
    case 'k':
    case 'K':
      setDisplay(B11100011,B11100111,B11101110,B11111100,B11111100,B11101110,B11100111,B11100011);
      break;
    case 'l':
    case 'L':
      setDisplay(B11100000,B11100000,B11100000,B11100000,B11100000,B11100000,B11111111,B11111111);
      break;
    case 'm':
    case 'M':
      setDisplay(B11100011,B11110111,B11111111,B11111111,B11100011,B11100011,B11100011,B11100011);
      break;
    case 'n':
    case 'N':
      setDisplay(B11100111,B11110111,B11110111,B11111111,B11111111,B11111111,B11101111,B11100111);
      break;
    case 'o':
    case 'O':
    case '0':
      setDisplay(B01111110,B11111111,B11100111,B11100111,B11100111,B11100111,B11111111,B01111110);
      break;
    case 'p':
    case 'P':
      setDisplay(B11111110,B11111111,B11100111,B11111111,B11111110,B11100000,B11100000,B11100000);
      break;
    case 'q':
    case 'Q':
      setDisplay(B01111110,B11111111,B11100111,B11100111,B11100011,B11101101,B11110110,B01111011);
      break;
    case 'r':
    case 'R':
      setDisplay(B11111110,B11111111,B11100111,B11111111,B11111110,B11100111,B11100111,B11100111);
      break;
    case 's':
    case 'S':
      setDisplay(B01111110,B11111111,B11100000,B11111110,B01111111,B00000111,B11111111,B01111110);
      break;
    case 't':
    case 'T':
      setDisplay(B11111110,B11111110,B00111000,B00111000,B00111000,B00111000,B00111000,B00111000);
      break;
    case 'u':
    case 'U':
      setDisplay(B11100111,B11100111,B11100111,B11100111,B11100111,B11100111,B11111111,B01111110);
      break;
    case 'v':
    case 'V':
      setDisplay(B11100111,B11100111,B11100111,B11100111,B11100111,B11100111,B01111110,B00111100);
      break;
    case 'w':
    case 'W':
      setDisplay(B11000110,B11000110,B11010110,B11010110,B11010110,B11111110,B01111100,B00101000);
      break;
    case 'x':
    case 'X':
      setDisplay(B11100111,B11100111,B01111110,B00111100,B00111100,B01111110,B11100111,B11100111);
      break;
    case 'y':
    case 'Y':
      setDisplay(B11100111,B11100111,B11100111,B01111110,B00111100,B00011000,B00011000,B00011000);
      break;
    case 'z':
    case 'Z':
      setDisplay(B11111111,B11111111,B00001111,B00011110,B01111000,B11110000,B11111111,B11111111);
      break;
    case '-':
      setDisplay(B00000000,B00000000,B00000000,B00111100,B00111100,B00000000,B00000000,B00000000);
      break;
    case '+':
      setDisplay(B00000000,B00011000,B00011000,B01111110,B01111110,B00011000,B00011000,B00000000);
      break;
    case '/':
      setDisplay(B00001100,B00001100,B00011000,B00011000,B00110000,B00110000,B01100000,B01100000);
      break;
    case '1':
      setDisplay(B00011100,B00111100,B01111100,B00011100,B00011100,B00011100,B00011100,B00011100);
      break;
    case '2':
      setDisplay(B01111110,B11111111,B11100111,B00001110,B00111000,B11100000,B11111111,B11111111);
      break;
    case '3':
      setDisplay(B11111110,B11111111,B00000111,B11111110,B11111110,B00000111,B11111111,B11111110);
      break;
    case '4':
      setDisplay(B11101110,B11101110,B11101110,B11111111,B11111111,B00001110,B00001110,B00001110);
      break;
    case '5':
      setDisplay(B11111111,B11111111,B11100000,B11111110,B11111111,B00000111,B11111111,B01111110);
      break;
    case '6':
      setDisplay(B01111110,B11111111,B11100000,B11111110,B11111111,B11100111,B11111111,B01111110);
      break;
    case '7':
      setDisplay(B11111111,B11111111,B00000111,B00001110,B00011100,B00111000,B00111000,B00111000);
      break;
    case '8':
      setDisplay(B01111110,B11111111,B11100111,B01111110,B01111110,B11100111,B11111111,B01111110);
      break;
    case '9':
      setDisplay(B01111110,B11111111,B11100111,B11111111,B01111111,B00000111,B1111111,B01111110);
      break;
    case ' ':
      clearScreen();
      break;
  }
}

void loop() { 
  char message[] = "SUCK MY BALLS";
  for (int i = 0; i < strlen(message); i++) {
    clearScreen();
    delay(100);
    writeChar(message[i]);
    delay(250);
    clearScreen();
  }
  delay(1000);


}
