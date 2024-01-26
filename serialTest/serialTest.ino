const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int SENSOR_PIN = 0;
const String RED = "red"; 
const String GREEN = "green"; 
const String BLUE = "blue"; 
const String YELLOW = "yellow"; 
const String CYAN = "cyan"; 
const String PURPLE = "purple"; 
const String WHITE = "white"; 

int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  bool off = true;
  Serial.println("Enter color:");
  while (Serial.available() == 0) {}
  String input = Serial.readString();
  input.trim();   
  input.toLowerCase();

  if (input == RED) 
  {
    ledRed();
    off = false;
  } 
  else if (input == GREEN) 
  {
    ledGreen();
    off = false;
  } 
  else if (input == BLUE) 
  {
    ledBlue();
    off = false;
  } 
  else if (input == YELLOW) 
  {
    ledYellow();
    off = false;
  } 
  else if (input == PURPLE) 
  {
    ledPurple();
    off = false;
  } 
  else if (input == CYAN) 
  {
    ledCyan();
    off = false;
  }  
  else if (input == WHITE) 
  {
    ledWhite();
    off = false;
  } 
  else 
  {
    ledOff();
  }

  off ? Serial.println("Color not recognized; LED is off.") : Serial.println("LED is colored " + input + ".");
}

void lightLed(int val) {
  if (val <= 0) {
    ledOff();
  } else if (val > 0 && val <= 146) {
    ledRed();
  } else if (val > 146 && val <= 146*2) {
    ledGreen();
  } else if (val > 146*2 && val <= 146*3) {
    ledBlue();
  } else if (val > 146*3 && val <= 146*4) {
    ledYellow();
  } else if (val > 146*4 && val <= 146*5) {
    ledCyan();
  } else if (val > 146*5 && val <= 146*6) {
    ledPurple();
  } else {
    ledWhite();
  }
}

void commandLight(String input) {
  if (input == RED) {
    ledRed();
  } else if (input == GREEN) {
    ledGreen();
  } else if (input == BLUE) {
    ledBlue();
  } else {
    ledOff();
  }
}

void ledOff()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void ledRed()
{
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void ledGreen()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
}

void ledBlue()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
}

void ledWhite()
{
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

void ledYellow()
{
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
}

void ledCyan()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

void ledPurple()
{
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
}