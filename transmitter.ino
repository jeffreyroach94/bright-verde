/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <FastLED.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
const char text1[] = "0";
const char text2[] = "1";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
  pinMode(2, INPUT);
}

// CRGB leds[4];

// void setup() {

//   FastLED.addLeds<WS2812, 6, GRB>(leds, 4);

// }

void loop() {\
  char text;

  int switchState = digitalRead(2);
  if (switchState == HIGH) {
    Serial.println("HIGH");
    radio.write(&text2, sizeof(text2));
  } else {
    Serial.println("LOW");
    radio.write(&text1, sizeof(text1));
  }

  delay(100);
}

// void loop() {
  
//   leds[0] = CRGB(255, 0, 0);
//   FastLED.show();
//   delay(500);  
//   leds[1] = CRGB(0, 255, 0);
//   FastLED.show();
//   delay(500);
//   leds[2] = CRGB(0, 0, 255);
//   FastLED.show();
//   delay(500);
//   leds[3] = CRGB(150, 0, 255);
//   FastLED.show();
//   delay(500);
// }