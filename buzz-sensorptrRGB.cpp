// Definir pines
const int pirPin = 2;
const int ldrPin = A0;
const int buzzerPin = 8;
const int ledRedPin = 9;
const int ledGreenPin = 10;
const int ledBluePin = 11;

// Definir umbral de luz
const int lightThreshold = 500;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  
  Serial.begin(9600); // Para depuración
}

void loop() {
  int pirState = digitalRead(pirPin);
  int lightLevel = analogRead(ldrPin);
  
  Serial.print("Movimiento: ");
  Serial.print(pirState);
  Serial.print(" - Luz: ");
  Serial.println(lightLevel);
  
  if (pirState == HIGH && lightLevel < lightThreshold) {
    // Movimiento sin luz
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledBluePin, LOW);
    tone(buzzerPin, 1000); // Tono de 1kHz
  } else if (pirState == LOW && lightLevel >= lightThreshold) {
    // No movimiento con luz
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledGreenPin, HIGH);
    digitalWrite(ledBluePin, LOW);
    tone(buzzerPin, 500); // Tono de 500Hz
  } else if (pirState == HIGH && lightLevel >= lightThreshold) {
    // Movimiento con luz
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledBluePin, HIGH);
    tone(buzzerPin, 1500); // Tono de 1.5kHz
  } else {
    // No movimiento sin luz
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledBluePin, LOW);
    noTone(buzzerPin); // Apagar el tono
  }
  
  delay(100); // Pequeño retraso para estabilizar la lectura
}
