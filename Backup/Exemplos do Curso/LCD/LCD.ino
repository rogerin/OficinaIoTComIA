#include <Wire.h> // Inicializa a biblioteca "Wire" para a comunicação do arduino com os outros dispositivos
#include <LiquidCrystal_I2C.h> // Inicializa a biblioteca "LiquidCrystal_I2C" para o manuseio do LCD através do módulo I2C

//Inicializa o display no endereço 0x27 contendo 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  lcd.init(); // Serve para iniciar a comunicação com o display já conectado
  lcd.backlight(); // Serve para ligar a luz do display

}

void loop() {
  lcd.setCursor(0, 0); // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("    WELCOME! "); // Escreve "TINY HOUSE" no LCD
  delay(5000); // Aguarda 5 segundos
  lcd.clear(); // Apaga o texto do lcd
  lcd.setCursor(0, 1); // Coloca o cursor do display na coluna 4 e linha 1
  lcd.print("   TINY HOUSE");
  delay(3000); // Aguarda 3 segundo
}
