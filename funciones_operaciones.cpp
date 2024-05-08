int s(int n1, int n2) {
	int resultado = n1+n2;
  	return resultado;
}
int r(int n1, int n2) {
	int resultado = n1-n2;
  	return resultado;
}
int m(int n1, int n2) {
	int resultado = n1*n2;
  	return resultado;
}
float d(float n1, float n2) {
	float resultado = n1/n2;
 	return resultado;
}

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop()
{
	String cadena;
  	double operacion;
  	int ope = random(1, 5);
  	int led = ope+1;
  	int num1 = random(1, 12);
  	int num2 = random(1, 12);
  if (ope == 1) {
  	cadena = "Suma";
    operacion = s(num1, num2);
  }
  else if(ope == 2) {
  	cadena = "Resta";
    operacion = r(num1, num2);
  }
  else if (ope == 3) {
  	cadena = "Multiplicacion";
    operacion = m(num1, num2);
  }
  else {
  	cadena = "Division";
    operacion = d(num1, num2);
  }
  Serial.println(ope);
  Serial.println(cadena);
  Serial.println("====================");
  Serial.println("El primer numero es: " + String(num1));
  Serial.println("El segundo numero " + String(num2));
  Serial.println("La " + cadena + "es " + String(operacion));
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}