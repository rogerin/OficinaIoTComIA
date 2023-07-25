#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h> // Inicializa a biblioteca "Wire" para a comunicação do arduino com os outros dispositivos
#include <LiquidCrystal_I2C.h> // Inicializa a biblioteca "LiquidCrystal_I2C" para o manuseio do LCD através do módulo I2C

//Inicializa o display no endereço 0x27 contendo 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define DHTPIN A2
#define DHTTYPE    DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600); //Inicializa o serial
  dht.begin();

  lcd.init(); // Serve para iniciar a comunicação com o display já conectado
  lcd.backlight(); // Serve para ligar a luz do display

  delay(1000); //Intervalo de 1 segundo

   sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;

   lcd.setCursor(0, 0); // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("    WELCOME! "); // Escreve "TINY HOUSE" no LCD
  delay(1000); // Aguarda 5 segundos
  lcd.clear(); // Apaga o texto do lcd
  lcd.setCursor(0, 1); // Coloca o cursor do display na coluna 4 e linha 1
  lcd.print("   TINY HOUSE");
  delay(3000); // Aguarda 3 segundo


}

void loop() {

 

   // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
    lcd.setCursor(0, 0); // Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("    Temperature! "); // Escreve "TINY HOUSE" no LCD
    lcd.setCursor(0, 1); // Coloca o cursor do display na coluna 4 e linha 1
    lcd.print(" "+ String(event.temperature)+" C");
    delay(3000);
     lcd.clear(); // Apaga o texto do lcd

  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));

     lcd.setCursor(0, 0); // Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("    Humidity! "); // Escreve "TINY HOUSE" no LCD
    lcd.setCursor(0, 1); // Coloca o cursor do display na coluna 4 e linha 1
    lcd.print(" "+ String(event.relative_humidity)+" %");
    delay(3000);
    lcd.clear(); // Apaga o texto do lcd
  }
 
  delay(1000); //Intervalo de 2 segundos
}
