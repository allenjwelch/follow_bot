
// Reading analog Infrared Sensor values
const int irFR = A0; // front-right
const int irBR = A1; // back-right
const int irBL = A2; // back-left
const int irFL = A3; // front-left

int irFRvalue = 0;        // value read from the Analog receiver
int irBRvalue = 0;        // value read from the Analog receiver
int irBLvalue = 0;        // value read from the Analog receiver
int irFLvalue = 0;        // value read from the Analog receiver

int irDetectionThreshold = 300;

// Reading digital UltraSonic sensor values
//const int usTrig = 9;
//const int usEcho = 10;
const int usTrig = A4;
const int usEcho = A5;

float duration, distance;

void setup() {
  pinMode(irFR, INPUT);
  pinMode(irBR, INPUT);
  pinMode(irBL, INPUT);
  pinMode(irFL, INPUT);
  pinMode(usTrig, OUTPUT);
  pinMode(usEcho, INPUT);

  // initialize serial communications
  Serial.begin(9600);
}

void loop() {
  irFRvalue = analogRead(irFR);
  irBRvalue = analogRead(irBR);
  irBLvalue = analogRead(irBL);
  irFLvalue = analogRead(irFL);

  digitalWrite(usTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(usTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(usTrig, LOW);

  duration = pulseIn(usEcho, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);

//  Serial.print("Front Right IR ");
//  Serial.println(irFRvalue);

  //set the threshold 
  if (irFRvalue < irDetectionThreshold) { 
    Serial.println("Object Detected in Front Right");
  }

  if (irBRvalue < irDetectionThreshold) { 
    Serial.println("Object Detected in Back Right");
  }

  if (irBLvalue < irDetectionThreshold) { 
    Serial.println("Object Detected in Back Left");
  }

  if (irFLvalue < irDetectionThreshold) { 
    Serial.println("Object Detected in Front Left");
  }

  if (distance < 15) {
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.println("---- Moving Forward -----" );
  }

  if (distance < 5) {
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.println("---- Moving Backward -----" );
  }



  
  delay(100);

}
