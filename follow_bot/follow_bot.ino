#include <AFMotor.h>

AF_DCMotor motorFL(1, MOTOR12_1KHZ);
AF_DCMotor motorBL(2, MOTOR12_1KHZ);
AF_DCMotor motorBR(3, MOTOR34_1KHZ);
AF_DCMotor motorFR(4, MOTOR34_1KHZ);

const int irFR = A0; // front-right
const int irFL = A3; // front-left
const int irBack = A1; // back

int irFRvalue = 0;     
int irFLvalue = 0;     
int irBackValue = 0;       

int irThreshold = 200;

const int usTrig = A4;
const int usEcho = A5;

float duration, distance;
bool leftDetection, rightDetection;

void setup() {
  Serial.begin(9600);         

  pinMode(irFR, INPUT);
  pinMode(irFL, INPUT);
  pinMode(irBack, INPUT);
  pinMode(usTrig, OUTPUT);
  pinMode(usEcho, INPUT);

  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
}


void moveForward(int speed) {
  Serial.println(F("FORWARD"));
  motorFL.setSpeed(speed);
  motorFL.run(FORWARD);
  motorFR.setSpeed(speed);
  motorFR.run(FORWARD);
  motorBL.setSpeed(speed);
  motorBL.run(FORWARD);
  motorBR.setSpeed(speed);
  motorBR.run(FORWARD);
}

void moveBackward(int speed) {
  Serial.println(F("BACK"));
  motorFL.setSpeed(speed);
  motorFR.setSpeed(speed);
  motorBL.setSpeed(speed);
  motorBR.setSpeed(speed);
  motorFL.run(BACKWARD);
  motorFR.run(BACKWARD);
  motorBL.run(BACKWARD);
  motorBR.run(BACKWARD);
}

void moveRight(int speed) {
  Serial.println(F("RIGHT"));
  motorFL.setSpeed(speed);
  motorFL.run(FORWARD);
  motorFR.setSpeed(speed / 2);
  motorFR.run(BACKWARD);
  motorBL.setSpeed(speed);
  motorBL.run(FORWARD);
  motorBR.setSpeed(speed / 2);
  motorBR.run(BACKWARD);
}

void moveLeft(int speed) {
  Serial.println(F("LEFT"));
  motorFL.setSpeed(speed / 2);
  motorFL.run(BACKWARD);
  motorFR.setSpeed(speed);
  motorFR.run(FORWARD);
  motorBL.setSpeed(speed / 2);
  motorBL.run(BACKWARD);
  motorBR.setSpeed(speed);
  motorBR.run(FORWARD);
}

void stopMoving(int speed) {
  Serial.println(F("STOP"));
  motorFL.setSpeed(speed);
  motorFR.setSpeed(speed);
  motorBL.setSpeed(speed);
  motorBR.setSpeed(speed);
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
}

void loop() {
  delay(100);
  irFRvalue = analogRead(irFR);
  irBackValue = analogRead(irBack);
  irFLvalue = analogRead(irFL);

  digitalWrite(usTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(usTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(usTrig, LOW);

  duration = pulseIn(usEcho, HIGH);
  distance = (duration*.0343)/2;
  
//  Serial.print("Distance: ");
//  Serial.println(distance);

  if ((distance <= 30 && distance >= 10)) {
    moveForward(100);
  } else if ((irFRvalue < irThreshold) && (irFLvalue > irThreshold)) {
    moveRight(200);
  } else if ((irFRvalue > irThreshold) && (irFLvalue < irThreshold)) {
    moveLeft(200);
  } else if ((irFRvalue < irThreshold) && (irFLvalue < irThreshold)) {
    moveBackward(100);
    delay(1000);
  } else if (irBackValue < irThreshold) {
    moveRight(200);
    delay(2000);
  } else if ((distance < 10 && distance > 1) || distance > 30){
    stopMoving(0);
  } 

}
