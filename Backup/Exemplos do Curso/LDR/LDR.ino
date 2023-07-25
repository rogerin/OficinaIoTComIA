#include <Wire.h>


const int LDR = A0;             // Pino analógico que o sensor está conectado
const int LED = 12;
int valorsensor ;               // valor que sera armazenado o valor do LDR
void setup() {

  pinMode(LDR, INPUT);          // Coloca a variavel LDR como entrada
  pinMode(LED, OUTPUT);
  Serial.begin(9600);           // inicializa a comunicação serial com a taxa de 9600 bps

}

void loop() {
  valorsensor = analogRead(LDR); // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorsensor
  Serial.print("LDR : " );      // Mostra o valor no monitor serial
  Serial.println(valorsensor);
  if (valorsensor < 600) { // Se o valor de VALORSENSOR for menos que 600

    Serial.println(" TURNO: NOITE  ");
    digitalWrite(LED, HIGH);
  } else {                    // Se não

    Serial.println("TURNO: DIA");
    digitalWrite(LED, LOW);
  }
  delay(1000);            // Aguarda 100 milisegundos
}
