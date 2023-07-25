#include <Servo.h> // Inicializa a biblioteca do servo motor
Servo servo; // Define uma variavel do tipo servo
void setup() {
  servo.attach(6); // Define o servo na porta 6
}

void loop() {
  servo.write(180); // Move o servo para a direção 180 que fecha a porta. Para abrir a porta mova o servo para a direção 90 ou menor
  delay(2000); // Aguarda 2 segundos
  servo.write(90); // Move o servo para a direção 90 abrindo a porta
  delay(2000); // Aguarda 2 segundos
}
