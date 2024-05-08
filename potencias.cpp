// Función para calcular la potencia Y de X
double calcularPotencia(int base, int exponente) {
  return pow(base, exponente);
}

// Función para calcular la raíz Y de X
double calcularRaiz(int radicando, int indice) {
  return pow(radicando, 1.0 / indice);
}

void setup() {
  
  Serial.begin(9600);

  
  randomSeed(analogRead(0));
}

void loop() {
  // Generación de números aleatorios para X e Y
  int X = random(1, 13); // Números aleatorios entre 1 y 12 para X
  int Y = random(1, 6);  // Números aleatorios entre 1 y 5 para Y

  // Cálculo de la potencia Y de X y la raíz Y de X
  double potencia = calcularPotencia(X, Y);
  double raiz = calcularRaiz(X, Y);

  
  Serial.print("X: ");
  Serial.print(X);
  Serial.print(", Y: ");
  Serial.println(Y);
  Serial.print("Potencia Y de X: ");
  Serial.println(potencia);
  Serial.print("Raiz Y de X: ");
  Serial.println(raiz);
  
  
  delay(3000);
}