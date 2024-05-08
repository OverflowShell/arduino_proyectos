// variables de los leds
int verde = 2; 
int rojo = 3; 

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  
  randomSeed(analogRead(0));
  
 
  int A = random(2, 11);
  int B = random(2, 11);
  
 
  int figura = random(1, 3);
  
// tipo float
  float area;
  if (figura == 1) {
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW);   
    area = A * B;
    Serial.print("El area del rectangulo es: ");
  } else if (figura == 2) {
    digitalWrite(verde, LOW);  
    digitalWrite(rojo, HIGH);   
    area = (float)(A * B) / 2;
    Serial.print("El area del triangulo es: ");
  } else {
    Serial.println("Error");
    return;
  }
  
  Serial.begin(9600);
  Serial.print("A: ");
  Serial.println(A);
  Serial.print("B: ");
  Serial.println(B);
  Serial.print("Figura: ");
  Serial.println(figura);
  Serial.println(area);
}

void loop() {
  
}