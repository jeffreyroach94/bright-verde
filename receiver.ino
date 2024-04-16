#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
const int LED_Pin = 6;

void setup() {

  pinMode(LED_Pin, OUTPUT);
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
    if (strcmp(text, "1") == 0) {
      digitalWrite(LED_Pin, HIGH);
    }
    else {
      digitalWrite(LED_Pin, LOW);
    }
  }
}