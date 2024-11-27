#include <SoftwareSerial.h>
#define rxPin 11 // Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 10 // Broche 10 en tant que TX, à raccorder sur RX du HC-05
SoftwareSerial mySerial(rxPin, txPin);
void setup()
{
 // define pin modes for tx, rx pins:
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 mySerial.begin(38400);
 Serial.begin(38400);
  Serial.println("╔══════════════════════════════════╗");
  Serial.println("║  Configure ton Module Bluetooth HC-05 pour ton Speeduino ║");
  Serial.println("║                       By Bolino08C                       ║");
  Serial.println("╚══════════════════════════════════╝");
  Serial.println("");
  Serial.println("HC-05 = Arduino MEGA 2560");
  Serial.println("RX    = 10");
  Serial.println("TX    = 11");
  Serial.println("Gnd   = Gnd");
  Serial.println("5v    = 5v");
  Serial.println("EN    = 3.3v");
  Serial.println("");
  Serial.println("AT+NAME=Speeduino   <= Nom du Bluetooth doit répondre :                                                     AT+NAME=Speeduino avec OK");
  Serial.println("AT+NAME?            <= Pour connaitre le Nom dans le HC-05");
  Serial.println("AT+PSWD=1234        <= Code PIN (mettre des guillements avant le PIN et Après) Bluetooth doit répondre :    AT+PSWD=1234 avec OK");
  Serial.println("AT+PSWD?            <= Pour connaitre le PIN dans le HC-05");
  Serial.println("AT+UART=115200,0,0  <= BAUDERATE HC-05 115200 doit répondre :                                               AT+UART=115200,0,0 avec OK");
  Serial.println("AT                  <= Test de liaison doit répondre :                                                      OK");
  Serial.println("");
  Serial.println("Config Moniteur Série : Pas de fin de ligne // 38400 baud ");
  Serial.println("");
  Serial.println("Entre ta commande AT: ");
}
void loop()
{
int i = 0;
char someChar[32] = {0};
// when characters arrive over the serial port...
if(Serial.available()) {
 do{
 someChar[i++] = Serial.read();
 delay(3);
 }while (Serial.available() > 0);
 mySerial.println(someChar);
 Serial.println(someChar);
}
while(mySerial.available())
 Serial.print((char)mySerial.read());
}
