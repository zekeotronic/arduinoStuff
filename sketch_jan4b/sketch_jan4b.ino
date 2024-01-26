#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ctype.h>

#define RED 11
#define GREEN 10
#define BLUE 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

bool bombArmed = false;
char bombCode[5] = "54321";
int keysPressed = 0;
char codeEntered[5];


void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (bombArmed) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   BOMB ARMED   ");
    delay(1000);
    lcd.clear();
    delay(500);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
    lcd.setCursor(0,0);
    lcd.print("   HOLD BUTTON  ");
    lcd.setCursor(0,1);
    lcd.print("   TO ARM BOMB  ");
    delay(1000);
    lcd.clear();
    delay(500);
  }
  
  tone(6, 440, 2000);
  Serial.println(analogRead(A0));
  if (analogRead(A0) >= 1023) {
    Serial.println("Button Pressed");
    bombArmed = true;

  }

  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    if (bombArmed == false) {
      codeEntered[keysPressed] = customKey;
      keysPressed++;
      if (codeEntered[0] == '#' && codeEntered[1] == '#' && codeEntered[2] == '#') {
        Serial.println("Bomb Armed");
        // lcd.setCursor(0,0);
        lcd.print("BOMB ARMED");
        lcd.clear();
      }
    }
  }
}

