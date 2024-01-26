#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ctype.h>

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
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("PRESS \"###\"");
  lcd.setCursor(0,1);
  lcd.print("TO ARM BOMB");
  // char customKey = customKeypad.getKey();
  
  // if (customKey){
  //   Serial.println(customKey);
  //   if (bombArmed == false) {
  //     codeEntered[keysPressed] = customKey;
  //     keysPressed++;
  //     if (codeEntered[0] == '#' && codeEntered[1] == '#' && codeEntered[2] == '#') {
  //       Serial.println("Bomb Armed");
  //       // lcd.setCursor(0,0);
  //       lcd.print("BOMB ARMED");
  //       lcd.clear();
  //     }
  //   }
  // }

}
