#include <AFMotor.h>

AF_DCMotor motorFL(1, MOTOR12_1KHZ);
AF_DCMotor motorBL(2, MOTOR12_1KHZ);
AF_DCMotor motorBR(3, MOTOR34_1KHZ);
AF_DCMotor motorFR(4, MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  motorFL.setSpeed(100);
  motorFR.setSpeed(100);
  motorBL.setSpeed(100);
  motorBR.setSpeed(100);
 
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
}

void loop() {
  
  Serial.print("FORWARD");
  motorFL.run(FORWARD);
  motorFR.run(FORWARD);
  motorBL.run(FORWARD);
  motorBR.run(FORWARD);

  delay(1000);
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
  delay(1000);

  Serial.print("BACKWARD");
  motorFL.run(BACKWARD);
  motorFR.run(BACKWARD);
  motorBL.run(BACKWARD);
  motorBR.run(BACKWARD);
  
  delay(1000);
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
  delay(1000);

  Serial.print("LEFT");
  motorFL.run(BACKWARD);
  motorFR.run(FORWARD);
  motorBL.run(BACKWARD);
  motorBR.run(FORWARD);

  delay(1000);
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
  delay(1000);

  Serial.print("RIGHT");
  motorFL.run(FORWARD);
  motorFR.run(BACKWARD);
  motorBL.run(FORWARD);
  motorBR.run(BACKWARD);
  
  delay(1000);
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
  delay(1000);


  Serial.print("tech");
  delay(1000);
}
