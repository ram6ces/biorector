const int stepPin = 2;
const int dirPin = 1;
const int sleepPin = 3;
const int enablePin = 4;

const int light = A0;

const int stepsPerRev=100;
int pulseWidthMicros = 200; 	// microseconds
int millisBtwnSteps = 1000;

void setup() {
 	Serial.begin(115200);
 	pinMode(stepPin, OUTPUT);
 	pinMode(dirPin, OUTPUT);
  pinMode(sleepPin, OUTPUT);
 	pinMode(enablePin, OUTPUT);
  pinMode(light, OUTPUT);

 
 	Serial.println("A4988 Initialized");
}
void UP(int turn) {
  //turn on the stepper
  Serial.println("Wake Up");  

  //wake up the stepper
  digitalWrite(sleepPin, HIGH);
  digitalWrite(enablePin, LOW);
  delay(3000);
  
  digitalWrite(dirPin, LOW);  // Enables the motor to move in a particular direction
    // Makes 200 pulses for making one full cycle rotation
  Serial.println("Turn");  

  for (int i = 0; i < turn * stepsPerRev; i++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(millisBtwnSteps);
  }
  //turn off the stepper
  Serial.println(F("Break"));
  digitalWrite(sleepPin,LOW);
  digitalWrite(enablePin, HIGH);
}
void DOWN(int turn) {
  //turn on the stepper
  Serial.println("Wake Up");  

  //wake up the stepper
  digitalWrite(sleepPin, HIGH);
  digitalWrite(enablePin, LOW);
  delay(3000);
  
  digitalWrite(dirPin, HIGH);  // Enables the motor to move in a particular direction
    // Makes 200 pulses for making one full cycle rotation
  Serial.println("Turn");  

  for (int i = 0; i < turn * stepsPerRev; i++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(millisBtwnSteps);
  }
  //turn off the stepper
  Serial.println("Break");
  digitalWrite(sleepPin,LOW);
  digitalWrite(enablePin, HIGH);
}
void lightON(){
  Serial.println("light ON");
  digitalWrite(light, HIGH);
  delay(5000);
}
void lightOFF(){
  Serial.println("light OFF");
  digitalWrite(light, LOW);
  delay(5000);
}

void loop() {
 	// Serial.println(F("Running clockwise"));
 	// digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
 	// // Makes 200 pulses for making one full cycle rotation
 	// for (int i = 0; i < stepsPerRev; i++) {
 	// 		digitalWrite(stepPin, HIGH);
 	// 		delayMicroseconds(pulseWidthMicros);
 	// 		digitalWrite(stepPin, LOW);
 	// 		delayMicroseconds(millisBtwnSteps);
 	// }
  // Serial.println(F("Break"));

 	// delay(2000); // One second delay

 	// Serial.println(F("Running counter-clockwise"));
 	// digitalWrite(dirPin, LOW); //Changes the rotations direction
 	// // Makes 400 pulses for making two full cycle rotation
 	// for (int i = 0; i < 2*stepsPerRev; i++) {
 	// 		digitalWrite(stepPin, HIGH);
 	// 		delayMicroseconds(pulseWidthMicros);
 	// 		digitalWrite(stepPin, LOW);
 	// 		delayMicroseconds(millisBtwnSteps);
 	// }

  // clockwise(3);
 	// delay(5000);

  lightOFF();
  delay(2000);
  //DOWN(5);

  delay(6000);

  //UP(5);
  delay(2000);
  lightON();
  delay(5000);
}