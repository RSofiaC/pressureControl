
/*
  Analog values in the Attiny for pressure control button
  Reads the value change from a pressure sensor and changes an LEDs luminosity.

  In order to place this code into the ATTINY85 the Arduino needs to be prepared this is a good tutorial:
  http://www.creativeapplications.net/tutorials/small-programmable-wearable-and-cheap-enjoying-the-attiny85-tutorial/

  The circuit:
  - Pressure Sensor's Vout (MPX2010/MPVZ5010) to A2 (ATTiny85 pin 3)
  - LED through 220ohm resistor to 1 (ATTiny85 pin 1)
  - 2 3V coin batteries can provide power or 5V (ATTiny85) to 5V in Arduino Board
  - Minimum Supply Voltage: 4.25V

  This code is in the public domain.

  modified Nov 2017
  by Regina Cantu (Lola)
 */
const int led = 1; // 0 or 1
const int pot = A2;

void setup() {
pinMode(led, OUTPUT); // set output explicitly w/the Tiny
pinMode(pot, INPUT);
}

void loop()
{
// trying to do the read> convert to PWM> write in one step 
//analogWrite(analogRead(pot)/4, led);

//read analog
 int an1 = analogRead(pot);

//convert to PWM
int an = (an1/4);    

//write analog
analogWrite(led, an); //set pwm
}
