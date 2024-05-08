int pin;
void rojo() {
	digitalWrite(12, HIGH);
  	delay(1000);
  	digitalWrite(12, LOW);
  	delay(1000);
}

void verde() {
	digitalWrite(11, HIGH);
  	delay(1000);
  	digitalWrite(11, LOW);
  	delay(1000);
}

void amarillo() {
	digitalWrite(10, HIGH);
  	delay(1000);
  	digitalWrite(10, LOW);
  	delay(1000);
}

void azul() {
	digitalWrite(9, HIGH);
  	delay(1000);
  	digitalWrite(9, LOW);
  	delay(1000);
}

void setup()
{
  for (pin=9;pin<=12;pin++) {
  	pinMode(pin, OUTPUT);
  }
}

void loop()
{
	randomSeed(analogRead(A0));
  	int num = random(1,5);
  	switch(num) {
  		case 1:
      		amarillo();
      		break;
      	case 2:
      		rojo();
      		break;
      	case 3:
      		verde();
     		break;
      	case 4:
      		azul();
      		break;
  }
  	
}