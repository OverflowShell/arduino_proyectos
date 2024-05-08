int N = 10;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int numeros[N]; 
  int grupo1[N], grupo2[N]; 
  int cantidadGrupo1 = 0, cantidadGrupo2 = 0;
  int sumatoriaGrupo1 = 0, sumatoriaGrupo2 = 0;

  
  for (int i = 0; i < N; i++) {
    numeros[i] = random(10, 51);

    if (numeros[i] >= 20 && numeros[i] <= 40) {
      grupo1[cantidadGrupo1] = numeros[i];
      cantidadGrupo1++;
      sumatoriaGrupo1 += numeros[i];
    } else {
      grupo2[cantidadGrupo2] = numeros[i];
      cantidadGrupo2++;
      sumatoriaGrupo2 += numeros[i];
    }
  }

  Serial.println("Grupo 1:");
  mostrarInformacionGrupo(grupo1, cantidadGrupo1, sumatoriaGrupo1);
  Serial.println("Grupo 2:");
  mostrarInformacionGrupo(grupo2, cantidadGrupo2, sumatoriaGrupo2);

  delay(5000); 
}

void mostrarInformacionGrupo(int grupo[], int cantidad, int sumatoria) {
  Serial.print("Numeros generados: ");
  for (int i = 0; i < cantidad; i++) {
    Serial.print(grupo[i]);
    Serial.print(" ");
  }
  Serial.println();
  
  Serial.print("Cantidad generada: ");
  Serial.println(cantidad);

  Serial.print("Sumatoria de los numeros: ");
  Serial.println(sumatoria);

  float promedio = cantidad > 0 ? (float)sumatoria / cantidad : 0;
  Serial.print("Promedio de los numeros: ");
  Serial.println(promedio, 2); 
}