#include <Arduino.h>


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "FreeMonoBold9pt7b.h"
#include "FreeMonoBold9pt7b.h"
#include "FreeSansBoldOblique18pt7b.h"

#define SCREEN_ADDRESS 0x3C

static const unsigned char PROGMEM image_battery_17_bits[] = {0x00,0x00,0x00,0x0f,0xff,0xfe,0x10,0x00,0x01,0x10,0x00,0x0d,0x70,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x70,0x00,0x0d,0x10,0x00,0x0d,0x10,0x00,0x01,0x0f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00};


Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() {
  // put your setup code here, to run once:
  
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

display.display();
Serial.begin(115200);

display.setTextSize(1);      
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);     
display.println("Hello, Gemini!");
display.display();
delay(1000);







display.clearDisplay();

display.setTextColor(1);
display.setTextWrap(false);
display.setFont(&FreeSansBoldOblique18pt7b);
display.setCursor(7, 54);
display.print("Player");

display.setCursor(24, 27);
display.print("MP3");

display.display();

pinMode(9, INPUT);
pinMode(7, INPUT);
pinMode(5, INPUT);
pinMode(3, INPUT);

digitalWrite(9, value);
digitalWrite(7, value);
digitalWrite(5, value);
digitalWrite(3, value);






/*
///



if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

display.clearDisplay();


  display.begin();

    display.setTextColor(1);
    display.setTextWrap(false);
    display.setCursor(3, 14);
    display.print("Now Playing:");

    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(2, 35);
    display.print("SONG111");

    display.setFont();
    display.setCursor(2, 40);
    display.print("Next Song:");

    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(3, 61);
    display.print("SONG111");

    display.drawBitmap(101, 3, image_battery_17_bits, 24, 16, 1);

*/
///
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("please work god");
  digitalRead(9);
  digitalRead(7);
  digitalRead(5);
  digitalRead(3);
  delay(300);
}




void TitleScreen(int delaytime){
  
  display.clearDisplay();

  display.setTextColor(1);
  display.setTextWrap(false);
  display.setFont(&FreeSansBoldOblique18pt7b);
  display.setCursor(7, 54);
  display.print("Player");

  display.setCursor(24, 27);
  display.print("MP3");

  display.display();
  delay(delaytime);

}





