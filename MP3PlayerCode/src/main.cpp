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



boolean LeftButton;

boolean RightButton;

boolean UpButton;

boolean DownButton;


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

digitalWrite(9, HIGH);
digitalWrite(7, HIGH);
digitalWrite(5, HIGH);
digitalWrite(3, HIGH);






}

String str(boolean thing) {
  if (thing)
    return "true";
  return "false";
}



void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("please work god");
  UpButton = digitalRead(9);
  LeftButton = digitalRead(7);
  DownButton = digitalRead(5);
  RightButton = digitalRead(3);
  Serial.println(str(UpButton)+" "+str(DownButton)+" " + str(LeftButton)+" " + str(RightButton));
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



