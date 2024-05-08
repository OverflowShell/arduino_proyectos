#include <Keypad.h>

const byte filas=4;
const byte columnas=4;
char teclas[filas][columnas]={{'1', '2', '3', 'A'},
                              {'4', '5', '6', 'B'},
                              {'7', '8', '9', 'C'},
                              {'*', '0', '#', 'D'}};
byte pinesFilas[filas] = { 9, 8, 7, 6 };
byte pinesColumnas[columnas] = { 5, 4, 3, 2 };
Keypad teclado=Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);
void imprimir(String cadena) {
	Serial.println(cadena);
}
void error() {
	Serial.println("No es del 1 al 7");
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char keypressed=teclado.getKey();
  if(keypressed!=NO_KEY) {
  	String cadena;
    switch(keypressed) {
    	case '1':
      		cadena="Lunes";
      		break;
      	case '2':
      		cadena="Martes";
      		break;
      	case '3':
      		cadena="Miercoles";
      		break;
      	case '4':
      		cadena="Jueves";
      		break;
      	case '5':
      		cadena="Viernes";
      		break;
      	case '6':
      		cadena="Sabado";
      		break;
      	case '7':
      		cadena="Domingo";
      		break;
    }

  if (isDigit(keypressed)&&keypressed!='8'&&keypressed!='9'&&keypressed!='0') {
  	imprimir(cadena);
  }
  else if(isAlpha(keypressed)||isGraph(keypressed)) {
  	error();
  }
  }
}