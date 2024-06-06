// C++ code
//
#include <Servo.h>
Servo motor;
int button1(12);
int button2(10);
int grados;
void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  motor.attach(8);
  Serial.begin(9600);
  
}

void loop()
{
  if(grados<=180 && grados>=0) {
    if(digitalRead(button1)==HIGH) {
    	grados++;
      	motor.write(grados);
    }
    if(digitalRead(button2)==HIGH) {
    	grados--;
      	motor.write(grados);
    }
    Serial.println(grados);
  }
  else if(grados ==181) {
  	grados=180;
  }
  else if(grados==-1) {
  	grados=1;
  }
}