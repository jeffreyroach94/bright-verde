#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <FastLED.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
const int LED_Pin = 6;

CRGB leds[4];

void setup() {

  pinMode(LED_Pin, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  FastLED.addLeds<WS2812, LED_Pin, GRB>(leds, 4);
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if (strcmp(text, "1") == 0) {
      leds[0] = CRGB(255, 0, 0);
      FastLED.show();
      delay(500);  
      leds[1] = CRGB(0, 255, 0);
      FastLED.show();
      delay(500);
      leds[2] = CRGB(0, 0, 255);
      FastLED.show();
      delay(500);
      leds[3] = CRGB(150, 0, 255);
      FastLED.show();
    }
    else {
      leds[0] = CRGB(0, 0, 0);
      leds[1] = CRGB(0, 0, 0);
      leds[2] = CRGB(0, 0, 0);
      leds[3] = CRGB(0, 0, 0);
      FastLED.show();
    }
  }

}