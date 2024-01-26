// Da Bomb
const int BUTTONPIN = 10;
const int REDPIN = 13;
const int GREENPIN = 12;
const int BLUEPIN = 11;
const int BUZZERPIN = 9;

bool armed = false;
int count = 0;

const int PUSHED = 0;
const int NOTPUSHED = 1;



void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTONPIN, INPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  // pinMode(BUZZERPIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState;

  buttonState = digitalRead(BUTTONPIN);

  if (buttonState == NOTPUSHED && armed == false) {
    digitalWrite(GREENPIN, HIGH);
  }

  if (buttonState == PUSHED && armed == false) {
    armed = true;
  }
  if (armed) {
    count++;
    Serial.println(count);
    if (count >= 15) {
      digitalWrite(GREENPIN, LOW);
      digitalWrite(REDPIN, HIGH);
      tone(BUZZERPIN,370,2000);
    }
    else if (count >= 10 ) {
      digitalWrite(GREENPIN, LOW);
      for (int i = 0; i <= 9; i++) {
        delay(100);
        digitalWrite(REDPIN, HIGH);
        delay(100);
        digitalWrite(REDPIN, LOW);
      }
    } else if (count >= 5) {
      digitalWrite(GREENPIN, LOW);
      for (int i = 0; i <= 3; i++) {
        delay(800);
        digitalWrite(REDPIN, HIGH);
        delay(100);
        digitalWrite(REDPIN, LOW);
      }
    } else {
      digitalWrite(GREENPIN, LOW);
      delay(800);
      digitalWrite(REDPIN, HIGH);
      delay(200);
      digitalWrite(REDPIN, LOW);
    }
    
  }
}
