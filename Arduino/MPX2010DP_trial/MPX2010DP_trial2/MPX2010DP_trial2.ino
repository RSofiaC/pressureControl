/**
 * WaterTankDepthSensor
 *
 * Uses an analog input to read the level of water in a tank using a
 * differential pressure transducer, with the result displayed in serial line
 *
 * Copyright 2009 Jonathan Oxer <jon@oxer.com.au>
 * Copyright 2009 Hugh Blemings <hugh@blemings.org>
 * http://www.practicalarduino.com/projects/water-tank-depth-sensor
 */


const int ledPin = 9;        // pin that the LED is attached to
int sensorValue = 0; 

void setup() {
  
  // Enable Serial output and ask WiServer to generate log messages (optional)
  Serial.begin( 9600 );
}

/**
 * Main program loop. everything is handled by callbacks
 * in the object itself. Nothing much happens
 */
void loop(){
   sensorValue = analogRead(A0);
   sensorValue = map(sensorValue, 573, 600, 0, 255);
  analogWrite(ledPin, sensorValue);
  Serial.print ("Tank Value");
  Serial.println (sensorValue);
}
