int rojo = A0;
int verde = A1;
int azul = A2;
int i,j,k;
void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop()
{
  i=0;
  while(i<5) {
  	analogWrite(rojo, 0);
    delay(1000);
    analogWrite(rojo, 676);
    delay(1000);
    i++;
  }
  analogWrite(rojo, 0);
  j=0;
  while(j<=5) {
  	analogWrite(verde, 0);
    delay(1000);
    analogWrite(verde, 676);
    delay(1000);
    j++;
  }
  analogWrite(verde, 0);
  k=0;
  while(k<=5) {
  	analogWrite(azul, 0);
    delay(1000);
    analogWrite(azul ,676);
    delay(1000);
    k++;
  }
  analogWrite(azul, 0);
}