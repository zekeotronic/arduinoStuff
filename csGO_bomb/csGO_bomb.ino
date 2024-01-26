#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RED 11
#define GREEN 10
#define BLUE 9
#define BTN A0
#define BUZZER_PIN 6

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool bombArmed = false;
bool countingDown = false;
bool exploded = false;

void redLED() {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

void redFlashingLED() {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    delay(250);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

}

void greenLED() {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
}

void blueLED() {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
}

void displayARM() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   BOMB ARMED   ");
    lcd.setCursor(0,1);
    lcd.print("HOLD BTN 2 START");
    delay(1000);
    lcd.clear();
    delay(500);
}

void displayARMED() {
    lcd.setCursor(0,0);
    lcd.print("   HOLD BUTTON  ");
    lcd.setCursor(0,1);
    lcd.print("   TO ARM BOMB  ");
    delay(1000);
    lcd.clear();
    delay(500);
}

void displayExploded() {
    lcd.setCursor(0,0);
    lcd.print("      BOOM      ");
    lcd.setCursor(0,1);
    lcd.print("      BOOM      ");
    delay(500);
    lcd.clear();
    delay(500);
}

void displayCOUNTDOWN() {
    lcd.clear();
    int digits[] = {1,0,0,0};

    for (int i = 1; i <= 600; i++) {
      if (digits[0] == 1) {
        digits[0] = 0;
        digits[1] = 9;
        digits[2] = 5;
        digits[3] = 9;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.println("   BOMB ARMED   ");
        lcd.setCursor(6, 1);
        lcd.print(digits[0]);
        lcd.print(digits[1]);
        lcd.print(":");
        lcd.print(digits[2]);
        lcd.print(digits[3]);
        Serial.print(digits[0]);
        Serial.print(digits[1]);
        Serial.print(":");
        Serial.print(digits[2]);
        Serial.println(digits[3]);
        redFlashingLED();
        delay(750);
      } else {
        digits[3]--;
        if (digits[3] < 0) {
          digits[2]--;
          digits[3] = 9; 
        }
        if (digits[2] < 0) {
          digits[1]--;
          digits[2] = 5;
        }
        if (digits[0] == 0 & digits[1] == 0 && digits[2] == 0 && digits[3] == 0) {
          exploded = true;
          bombArmed = false;
          countingDown = false;
          break;
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.println("   BOMB ARMED   ");
        lcd.setCursor(6, 1);
        lcd.print(digits[0]);
        lcd.print(digits[1]);
        lcd.print(":");
        lcd.print(digits[2]);
        lcd.print(digits[3]);
        Serial.print(digits[0]); 
        Serial.print(digits[1]);
        Serial.print(":");
        Serial.print(digits[2]);
        Serial.println(digits[3]);
        redFlashingLED();
        delay(750);
      }
    }

    Serial.print(digits[0]);
    Serial.print(digits[1]);
    Serial.print(":");
    Serial.print(digits[2]);
    Serial.print(digits[3]);

}

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {

  if (exploded == true) {
    redLED();
    displayExploded();
  }

  if (bombArmed == true && countingDown == false && exploded == false) {
    redLED();
    displayARM();
  } 
  
  if (bombArmed == false && countingDown == false) {
    greenLED();
    displayARMED();
  } 
  
  if (bombArmed == true && countingDown == true ) {
    redFlashingLED();
    displayCOUNTDOWN();
  }

  if (analogRead(A0) >= 1000 && bombArmed == false) {
    Serial.println("Button Pressed");
    bombArmed = true;
  } 
  
  if (analogRead(A0) >= 1000 && bombArmed == true) {
    Serial.println("Button Pressed");
    countingDown = true;
  }

}

