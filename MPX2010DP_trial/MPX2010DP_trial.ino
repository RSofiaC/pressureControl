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

int sensorValue      = 0;
int constrainedValue = 0;
int tankLevel        = 0;
int TANK_SENSOR;


#define TANK_EMPTY 0
#define TANK_FULL  1023
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
  constrainedValue = constrain( sensorValue, TANK_EMPTY, TANK_FULL );
  tankLevel = map( constrainedValue, TANK_EMPTY, TANK_FULL, 0, 100 );
  Serial.print ("Tank Value");
  Serial.println (sensorValue);
}
