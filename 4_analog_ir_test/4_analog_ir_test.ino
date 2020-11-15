// Reading analog Infrared Sensor values
const int irFR = A0; // front-right
const int irBR = A1; // back-right
const int irBL = A2; // back-left
const int irFL = A3; // front-left


int irFRvalue = 0;        // value read from the Analog receiver
int irBRvalue = 0;        // value read from the Analog receiver
int irBLvalue = 0;        // value read from the Analog receiver
int irFLvalue = 0;        // value read from the Analog receiver

int irDetectionThreshold = 100;

void setup() {
  pinMode(irFR, INPUT);
  pinMode(irBR, INPUT);
  pinMode(irBL, INPUT);
  pinMode(irFL, INPUT);

  // initialize serial communications
  Serial.begin(9600);
}

void loop() {
  irFRvalue = analogRead(irFR);
  irBRvalue = analogRead(irBR);
  irBLvalue = analogRead(irBL);
  irFLvalue = analogRead(irFL);

  // print the results to the serial monitor:
  Serial.print("Front Right = ");
  Serial.println(irFRvalue);

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

 
  delay(500);

}
