
#define TRIGGER_PIN  7  // Pin del trigger del sensor
#define ECHO_PIN     6  // Pin del echo del sensor
#define MAX_DISTANCE 800 // MAS

#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5
#define LED8_PIN 8
#define LED9_PIN 9
#define BUZZER_PIN 10

#define INTERVALO_LED 20 // MENOS

void setup() {
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED8_PIN, OUTPUT);
  pinMode(LED9_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

 
  unsigned long duracion = pulseIn(ECHO_PIN, HIGH);
  
 
  unsigned int distancia = duracion / 58; // La velocidad del sonido es de aproximadamente 58 μs/cm
  
  
  if (distancia > MAX_DISTANCE) {
    distancia = MAX_DISTANCE;
  }
  
  
  int num_leds = distancia / INTERVALO_LED;

  
  for (int i = 1; i <= 6; i++) {
    digitalWrite(i + 1, i <= num_leds ? HIGH : LOW);
  }
  
  // Reproducimos un sonido más agudo o más grave dependiendo de la distancia
  int frecuencia = map(distancia, 0, 200, 500, 200); // Mapeamos la distancia a una frecuencia audible
  tone(BUZZER_PIN, frecuencia);

  
  delay(100);
}