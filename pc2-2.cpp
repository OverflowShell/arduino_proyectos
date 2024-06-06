#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;

char teclas[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFilas[FILAS] = {2, 3, 4, 5};
byte pinesColumnas[COLUMNAS] = {6, 7, 8, 9};

Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

const int ledsSeriales[] = {10, 11, 12, 13, A0};
const int ledsParalelos[] = {A1, A2, A3, A4, A5};
const int ledsMixtos[] = {A0, A1, A2, A3, A4};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledsSeriales[i], OUTPUT);
    pinMode(ledsParalelos[i], OUTPUT);
    pinMode(ledsMixtos[i], OUTPUT);
  }
  
  apagarTodosLosLeds();
}

void loop() {
  char tecla = teclado.getKey();

  if (tecla != NO_KEY) {
    if (tecla == '1') {
      encenderSerial();
    } else if (tecla == '2') {
      encenderParalelo();
    } else if (tecla == '3') {
      encenderMixto();
    }
  }
}

void encenderSerial() {
  apagarTodosLosLeds();
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledsSeriales[i], HIGH);
    delay(100);
  }
}

void encenderParalelo() {
  apagarTodosLosLeds();
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledsParalelos[i], HIGH);
  }
}

void encenderMixto() {
  apagarTodosLosLeds();
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledsMixtos[i], HIGH);
    delay(50);
  }
}

void apagarTodosLosLeds() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledsSeriales[i], LOW);
    digitalWrite(ledsParalelos[i], LOW);
    digitalWrite(ledsMixtos[i], LOW);
  }
}