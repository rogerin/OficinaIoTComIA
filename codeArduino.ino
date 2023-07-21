int incomingByte = 0; // for incoming serial data

const int ledLego = 9;
const int ledPneu = 10;
const int ledOtg = 11;


void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(ledLego, OUTPUT);
  pinMode(ledPneu, OUTPUT);
  pinMode(ledOtg, OUTPUT);

  
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
 
  
      switch(incomingByte) { 
          case '0':
            Serial.println('lego');
            digitalWrite(ledLego, HIGH);
            digitalWrite(ledPneu, LOW);
            digitalWrite(ledOtg, LOW);
            

            break;

          case '1':
            Serial.println('pneu');
             digitalWrite(ledPneu, HIGH);
            digitalWrite(ledLego, LOW);
            digitalWrite(ledOtg, LOW);


            break;

          case '3':
            Serial.println('otg');
            digitalWrite(ledOtg, HIGH);
            digitalWrite(ledPneu, LOW);
            digitalWrite(ledLego, LOW);

            break;

          default:
            // handle unwanted input here
            break;
    }


  }
}