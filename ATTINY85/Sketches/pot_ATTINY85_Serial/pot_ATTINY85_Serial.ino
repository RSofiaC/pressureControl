
/*
  Analog values in the Attiny for pressure control button
  Reads the value change from a pressure sensor changes an LEDs luminosity and prints the serial values.

  In order to place this code into the ATTINY85 the Arduino needs to be prepared this is a good tutorial:
  http://www.creativeapplications.net/tutorials/small-programmable-wearable-and-cheap-enjoying-the-attiny85-tutorial/
  The Serial communication tutorial:
  https://www.hackster.io/porrey/easy-serial-on-the-attiny-2676e6

  The circuit:
  - Pressure Sensor's Vout (MPX2010/MPVZ5010) to A2 (ATTiny85 pin 3)
  - 2 LEDs through 220ohm resistors to 1 & 0 (ATTiny85 pins 5 & 6)
  - USB to TTL cable provides voltage and serial communication
  - Minimum Supply Voltage: 4.25V

  This code is in the public domain.

  modified Nov 2017
  by Regina Cantu (Lola)
*/
#include <SoftwareSerial.h>
#include <avr/power.h>

//Define the RX and TX pins. Avoid DO(pin5) and D2(pin7) if using I2C
#define RX 3 //pin2 in ATTiny85
#define TX 2 //pin7 in ATTiny85
//Define the software based serial port. Using name Serial so that software that supports hardware base serial can read it.
SoftwareSerial TSerial(RX, TX);

//Define the LED and analog pins
const int led1 = 1;
const int led2 = 0;
const int sensor = A2;


void setup() {
  clock_prescale_set(clock_div_1);
  
  // Initiazlize the serial port
  TSerial.begin(9600);


  //Initialize the pins as input and output
  pinMode(led1, OUTPUT); // set output explicitly w/the Tiny
  pinMode(led2, OUTPUT); // set output explicitly w/the Tiny
  pinMode(sensor, INPUT);
}

void loop() {
  // trying to do the read> convert to PWM> write in one step
  //analogWrite(analogRead(pot)/4, led);

  //read analog
  int an1 = analogRead(sensor);

  //convert to PWM
  int an = (an1 / 4);

  //write analog
  analogWrite(led1, an); //set pwm
  analogWrite(led2, an); //set pwm
  TSerial.println(an);
}
