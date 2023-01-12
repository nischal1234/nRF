/* Arduino to nrf connection
  Arduino  SCK MISO  MOSI  SS
   Uno     13  12  11  10
   Nano    13  12  11  10
   Mega    52  50  51  53 */
//This is Transmitter code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text); // for debug 
    Serial.println("i got data");// for debug 
  }
}
