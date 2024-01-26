int pins[10]   =  { 2, 3, 4, 5, 6,  7,  8,  9,   10,  11  };
int values[10] =  { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int outputs[10] = { 0, 0, 0, 0, 0,  0,  0,  0,   0,   0   };
int delayTime = 125;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  count(1023, 1, "a");
  count(1023, 1, "d");
  // takeInput();
}

void takeInput() {
  Serial.println("Enter number between 0 and 1023:");
  while (Serial.available() == 0) {}
  int input = Serial.parseInt();
  if (input > 1023 || input < 0 ) {
    Serial.println("Invalid Number");
  } else {
    Serial.println("You have selected " + String(input));
    convertToBinary(input);
    delay(delayTime);
  }
}

void count(int high, int low, char direction) {
  if (direction == "d" || direction == "D") {
    for (int i = high; i >= low; i--) {
      Serial.println(i);
      convertToBinary(i);
      delay(delayTime);
    }
  } else {
    for (int i = low; i <= high; i++) {
      Serial.println(i);
      convertToBinary(i);
      delay(delayTime);
    }
  }
}

void reset() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(pins[i], LOW);
  }
}

void convertToBinary(int number) {
  int num = number;
  for (int i = 9; i >=0; i--) {
    if (num >= values[i]) {
      outputs[i] = 1;
      num -= values[i];
    } else {
      outputs[i] = 0;
    }
  }
  lightLEDS();
}

void lightLEDS() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(pins[i], outputs[i]);
  }
}