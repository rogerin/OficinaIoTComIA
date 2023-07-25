const int sensor = 9; // Guarda o valor 8 na variável int (inteiro) chamado sensor
int leitura = 0; // Define uma variável chamada leitura

#define BUZZER_PIN 10

#define SILENCE  0
#define NOTE_B7  3951
#define NOTE_CS8 4435
#define NOTE_E8  5274



void setup() {
  pinMode(sensor, INPUT); // Define a variável sensor como um pino e como um "INPUT" ou entrada
  pinMode(BUZZER_PIN, OUTPUT); 
  
  Serial.begin(9600); // Começa o serial com uma taxa de transferência de 9600
}

void loop() {
  leitura = digitalRead(sensor); // Armazena o valor do sensor na variável leitura
  // A função "digitalRead" faz a leitura da variável como HIGH (ativo) e LOW (desativo)

  // O "if" é uma função condicional onde só irá passar ele se essa condição for atendida
  if (leitura == HIGH) {
    Serial.println("Movimento detectado"); // Escreve no serial o valor da leitura
     playCommunicatorSound();
  }
  // A função else é nada mais que a consequência de se o "if" acima não for atendido
  else  {
    Serial.println("Nenhum movimento detectado"); // Escreve no serial o valor do sensor
    noTone(BUZZER_PIN);
  }

  delay(200); // Tempo (0.2 segundos) para diminuir a velocidade do código
}


static const int notes[] = {
  NOTE_CS8, SILENCE,  NOTE_CS8, SILENCE,
  NOTE_B7,  NOTE_CS8, SILENCE,  NOTE_E8,
  SILENCE,  NOTE_CS8, SILENCE,  SILENCE
};

void playCommunicatorSound() {
  for (int i=0; i<12; i+=1) {
    if (notes[i] != SILENCE) {
      tone(BUZZER_PIN, notes[i], 102);
    }

    delay(150);
  }
}
