#define DIG1 7
#define DIG2 10
#define DIG3 11
#define DIG4 A1
#define A 8
#define B 12
#define C 3
#define D 5
#define E 6
#define F 9
#define G 2
#define DP 4
#define CLN 13
#define dw(x,y) digitalWrite(x,y)
void display(int);

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(DIG1, OUTPUT);
  pinMode(DIG2, OUTPUT);
  pinMode(DIG3, OUTPUT);
  pinMode(DIG4, OUTPUT);
}

void loop() {
  dw(DIG1, HIGH);
  dw(DIG2, HIGH);
  dw(DIG3, HIGH);
  dw(DIG4, HIGH);
  for (int i = 9; i >= 0; i--) {
    display(i);
    delay(1500);
  }
}

void display(int number) {
  switch (number) {
    case 1:
      dw(A,HIGH);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,HIGH);
      dw(E,HIGH);
      dw(F,HIGH);
      dw(G,HIGH);
      dw(DP,HIGH);
      break;
    case 2:
      dw(A,LOW);
      dw(B,LOW);
      dw(C,HIGH);
      dw(D,LOW);
      dw(E,LOW);
      dw(F,HIGH);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 3:
      dw(A,LOW);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,LOW);
      dw(E,HIGH);
      dw(F,HIGH);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 4:
      dw(A,HIGH);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,HIGH);
      dw(E,HIGH);
      dw(F,LOW);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 5:
      dw(A,LOW);
      dw(B,HIGH);
      dw(C,LOW);
      dw(D,LOW);
      dw(E,HIGH);
      dw(F,LOW);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 6:
      dw(A,LOW);
      dw(B,HIGH);
      dw(C,LOW);
      dw(D,LOW);
      dw(E,LOW);
      dw(F,LOW);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 7:
      dw(A,LOW);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,HIGH);
      dw(E,HIGH);
      dw(F,HIGH);
      dw(G,HIGH);
      dw(DP,HIGH);
      break;
    case 8:
      dw(A,LOW);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,LOW);
      dw(E,LOW);
      dw(F,LOW);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 9:
      dw(A,LOW);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,LOW);
      dw(E,HIGH);
      dw(F,LOW);
      dw(G,LOW);
      dw(DP,HIGH);
      break;
    case 0:
      dw(A,LOW);
      dw(B,LOW);
      dw(C,LOW);
      dw(D,LOW);
      dw(E,LOW);
      dw(F,LOW);
      dw(G,HIGH);
      dw(DP,HIGH);
      break;
  }
}