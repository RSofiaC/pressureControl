const int led = 0; // 0 or 1
const int pot = 2;

void setup() {
pinMode(led, OUTPUT); // set output explicitly w/the Tiny
pinMode(pot, INPUT);
}

void loop()
{
// read the pot, divide by 4, and then fade (ignoring the actual illumination curve of the LED for now)
analogWrite(analogRead(pot)/4, led);
}
