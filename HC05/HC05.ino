//---------------------- RX PIN  ---------------------- D10 (ARDUINO) --> RX (HC05 BLUETOOTH MODULE)
//---------------------- TX PIN  ---------------------- D11 (ARDUINO) --> TX (HC05 BLUETOOTH MODULE)

#include <SoftwareSerial.h>

SoftwareSerial btSerial(10, 11); // RX, TX

char recivedData;  // Variable to store recived data

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  if (btSerial.available() > 0)
  {
    recivedData = btSerial.read();
    Serial.println(recivedData);
  }
}
