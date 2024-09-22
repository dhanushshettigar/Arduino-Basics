//-------------------------------------------- D10 (ARDUINO) --> TX (HC05 BLUETOOTH MODULE)
//-------------------------------------------- D11 (ARDUINO) --> RX (HC05 BLUETOOTH MODULE)

#include <SoftwareSerial.h>

SoftwareSerial btSerial(10, 11);

char receivedData;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  if (btSerial.available() > 0)
  {
    receivedData = btSerial.read();
    Serial.println(receivedData);
  }
}
