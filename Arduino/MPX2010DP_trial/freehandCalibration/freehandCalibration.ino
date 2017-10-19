// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to

// variables:
int sensorValue = 0;         // the sensor value

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  //sensorValue = map(sensorPin, 170, 180, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  //sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  //analogWrite(ledPin, sensorValue);
  Serial.println (sensorValue);

}
