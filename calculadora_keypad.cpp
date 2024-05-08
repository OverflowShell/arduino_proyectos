#include <Keypad.h>

const byte numFil=4;
const byte numCol=4;
char matTec[numFil][numCol]={{'1', '2', '3', 'A'},{'4', '5', '6', 'B'},{'7', '8', '9', 'C'},{'*', '0', '#', 'D'}};

byte filPin[numFil] = { 9, 8, 7, 6 };
byte colPin[numCol] = { 5, 4, 3, 2 };
Keypad teclado=Keypad(makeKeymap(matTec),filPin,colPin,numFil,numCol);

int led =0,pin;
int arreglo[3];
int indarreglo=0;

  


void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50);
  for (pin=10;pin<=13;pin++){
    pinMode(pin,OUTPUT);}
  Serial.println("============= Ingrese 3 Numeros :==============");
}

void loop() {
  String cadena;
  float resultado;
  char Keypressed = teclado.getKey();
  if (Keypressed!= NO_KEY&&isDigit(Keypressed)) {
		arreglo[indarreglo]=Keypressed-48; //para pasarlo a numerico
		Serial.println(Keypressed);
		indarreglo++;
     }
  if (indarreglo==3) {
    cadena = devuelveoperacion(arreglo[2]);
    if (led!=0) {
      resultado = evaluaresultado(arreglo[2]);
      Serial.println("Operaciones cadena");
	  Serial.println("Numero Uno es: "+String(arreglo[0]));
	  Serial.println("Numero Dos es "+String(arreglo[1]));
      Serial.println("El Resultado es: "+String(resultado));
    }
	digitalWrite(led, LOW);
	indarreglo=0;led=0; resultado=0;
	Serial.println("Ingrese 3 Numeros");
  }
}
void error() {
	Serial.println("El tercer numero debe ser entre 1-4");                
}
String devuelveoperacion(int operacion) {
	String str;
    switch(operacion) {
      	case 1:
      		str="Suma";
      		led=10;
      		break;
      	case 2:
      		str="Resta";
      		led=11;
      		break;
      	case 3:
      		str="Multiplicacion";
      		led=12;
      		break;
      	case 4:
      		str="Division";
      		led=13;
      		break;
      	default:
      		error();break;
  }
  return str;
}
float evaluaresultado(char operacion) {
	float resu=0;
  	int numero1, numero2;
  	numero1 = arreglo[0];
  	numero2 = arreglo[2];
  	switch(operacion) {
      case 1:
      	resu=numero1+numero2;
      	digitalWrite(led, HIGH);
      	delay(1000);
      	break;
      case 2:
      	resu=arreglo[0]-arreglo[1];
      	digitalWrite(led, HIGH);
      	delay(1000);
      	break;
      case 3:
      	resu=arreglo[0]*arreglo[1];
      	digitalWrite(led, HIGH);
      	delay(1000);
      	break;
      case 4:
      	resu=(float)arreglo[0]/arreglo[1];
      	digitalWrite(led, HIGH);
      	delay(1000);
      	break;
      default:
      	resu=0;
      	break;
    }
  return resu;
}