#include<SoftwareSerial.h>

#define SPEED_1 5
#define DIR_1 4
#define SPEED_2 6
#define DIR_2 7

int speed = 100;
int turnSpeed = 255;
int turnDelay = 600;
char mode = 's';

SoftwareSerial mySerial(11, 10);

void goForward() {
  digitalWrite(DIR_1, HIGH);
  digitalWrite(DIR_2, HIGH);

  analogWrite(SPEED_1, speed);
  analogWrite(SPEED_2, speed);
}

void goBackward() {
  digitalWrite(DIR_1, LOW);
  digitalWrite(DIR_2, LOW);

  analogWrite(SPEED_1, speed);
  analogWrite(SPEED_2, speed);
}

void stop() {
  analogWrite(SPEED_1, 0);
  analogWrite(SPEED_2, 0);
}

void turn(int s1, int s2) {
  analogWrite(SPEED_1, s1);
  analogWrite(SPEED_2, s2);

  delay(turnDelay);
  mode = 's';
}

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);

  pinMode(SPEED_1, OUTPUT);
  pinMode(DIR_1, OUTPUT);
  pinMode(SPEED_2, OUTPUT);
  pinMode(DIR_2, OUTPUT);
}

void loop() {
  if (mySerial.available() > 0) {
    char str = (char)mySerial.read();

    Serial.write(str);

    if(str == 'f' || str == 'b' || str == 's' || str == 'l' || str == 'r'){
      mode = str;
    }
  }

  if(mode == 'f'){
    goForward();
  }
  if(mode == 'b'){
    goBackward();
  }
  if(mode == 'l'){
    turn(turnSpeed, 0);
  }
  if(mode == 'r'){
    turn(0, turnSpeed);
  }
  if(mode == 's'){
    stop();
  }
}