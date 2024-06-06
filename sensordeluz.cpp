// C++ code
//
int sensorluz = 0;
int cuantaluz;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  cuantaluz = map(analogRead(sensorluz),0,1023,0,100);
  Serial.print("Analog reading = ");
  Serial.println(cuantaluz);
  delay(500);
}