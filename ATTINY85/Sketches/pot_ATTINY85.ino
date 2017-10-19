const int led = 1; // 0 or 1
const int pot = A3;

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
