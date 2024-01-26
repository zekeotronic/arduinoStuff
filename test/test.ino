int ledPin = 8;
int delayTime = 150;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(ledPin, HIGH);
  // delay(delayTime);
  // digitalWrite(ledPin, LOW);
  // delay(delayTime);

  for (int i = 1000; i >= 150; i = i - 5) {
    digitalWrite(ledPin, HIGH);
    delay(i);
    digitalWrite(ledPin, LOW);
    delay(i);
    Serial.println(i);
  }
}
