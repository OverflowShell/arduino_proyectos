// Definir el pin del LED
int ledPin = 9;
// Definir el valor del resistor en ohmios
float resistorValue = 220; // Por ejemplo, 220 ohmios

void setup() {
 
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Definir el nivel de brillo deseado (de 0 a 255)
  int brightness = 100; // Por ejemplo, 200

  // Encender el LED con el nivel de brillo definido
  analogWrite(ledPin, brightness);

  // Calcular la tension en el circuito (en voltios)
  float voltage = brightness * (5.0 / 255.0); // Convertir el valor de brillo a voltios (5V referencia)

  // Calcular la corriente en el circuito (en amperios)
  float current = voltage / resistorValue;

  // Calcular la potencia consumida (en vatios)
  float power = voltage * current;

  // Imprimir el consumo de energía
  Serial.print("Nivel de brillo: ");
  Serial.print(brightness);
  Serial.print(", Consumo de energia: ");
  Serial.print(power);
  Serial.println(" vatios");

  // Esperar un momento antes de repetir el bucle
  delay(1000);
}
// CUANDO PONES 1 DE BRILLO O VALORES ASI DE BAJOS SALE 0 POR
// LA PRECICION LIMITADA DE LA SIMULACION
// LAS SIMULACIONES TIENEN CIERTAS LIMITACIONES EN CUANTO A LA PRECICION