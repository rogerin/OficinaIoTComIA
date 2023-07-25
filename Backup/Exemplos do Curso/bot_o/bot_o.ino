const int botao_1 = 2; // Define o botão 1 no pino 2
const int botao_2 = 3; // --

#include <Servo.h> // Inicializa a biblioteca do servo motor
Servo servo; // Define uma variavel do tipo servo

Servo servo2; // Define uma variavel do tipo servo

int teste, teste2 = 0;

void setup() {
  pinMode(botao_1, INPUT_PULLUP); // Define o botão 1 como INPUT ou entrada
  pinMode(botao_2, INPUT_PULLUP); // 
  
  servo.attach(6); // Define o servo na porta 6
  servo2.attach(5); // Define o servo na porta 6
  

  Serial.begin(9600);
}

void loop() {
  teste = digitalRead(botao_1);
  if (teste == LOW) {
    Serial.println("O botão 1 foi apertado!"); 
    servo.write(220);
    delay(3000);
    servo.write(90);
  }
  
  teste2 = digitalRead(botao_2);
  if (teste2 == LOW) {
    Serial.println("O botão 2 foi apertado!"); 
    servo2.write(220);
    delay(3000);
    servo2.write(90);
  }

}
