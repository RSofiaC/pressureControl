// pins
const int sensorPin = 2;
const int ledPin = 1; 

// variables:
int sensorValue = 0;

void setup() {
 // Serial.begin(9600);
pinMode(ledPin, OUTPUT); // set output explicitly w/the Tiny
pinMode(sensorPin, INPUT);
}
//int LEDDelay = 0;
void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);
  
  // map the sensor to the LED
  sensorValue = map(sensorValue, 1, 1010, 8, 255);
 
 // fade the LED using the maped value:
    analogWrite(ledPin, sensorValue);
 
  delay(100);
}
