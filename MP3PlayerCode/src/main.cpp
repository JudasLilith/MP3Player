#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "FreeMonoBold9pt7b.h"
#include "FreeMonoBold9pt7b.h"
#include "FreeSansBoldOblique18pt7b.h"



//defines the buttons
boolean LeftButton;
boolean RightButton;
boolean UpButton;
boolean DownButton;

// God I fucking hate C++
String str(boolean thing) {
  if (thing)
    return "true";
  return "false";
}

static const unsigned char PROGMEM image_battery_17_bits[] = {0x00,0x00,0x00,0x0f,0xff,0xfe,0x10,0x00,0x01,0x10,0x00,0x0d,0x70,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x80,0x00,0x0d,0x70,0x00,0x0d,0x10,0x00,0x0d,0x10,0x00,0x01,0x0f,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00};
static const unsigned char PROGMEM image_Layer_6_bits[] = {0x80};





#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);




void TitleScreen(){
  
  display.clearDisplay();

  display.setTextColor(1);
  display.setTextWrap(false);
  display.setFont(&FreeSansBoldOblique18pt7b);
  display.setCursor(7, 54);
  display.print("Player");

  display.setCursor(24, 27);
  display.print("MP3");

  display.display();

}

void MainScreen(){

  display.clearDisplay(); // maybe being unable to clear is the reaosn....

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
  display.drawBitmap(35, 5, image_Layer_6_bits, 1, 1, 1);

  display.display();

}






void setup() {  // put your setup code here, to run once:

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  Serial.begin(115200);

  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);     
  display.display();
  delay(1000);

  //TitleScreen();
  MainScreen();

  delay(100);

  pinMode(9, INPUT);
  pinMode(7, INPUT);
  pinMode(5, INPUT);
  pinMode(3, INPUT);

  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(3, HIGH);

  delay(400);
  Serial.println("this should work somehow"); //so this somehow worked, now we do know it gets to this point


}













void loop() {
  // put your main code here, to run repeatedly:
  UpButton = digitalRead(9);
  LeftButton = digitalRead(7);
  DownButton = digitalRead(5);
  RightButton = digitalRead(3);
  Serial.println(str(UpButton)+" "+str(DownButton)+" " + str(LeftButton)+" " + str(RightButton));
  if (!(UpButton)){
    //MainScreen(12);
    while ( !(DownButton) ){
      delay(300);
      Serial.println("yay it worked");
    }
  }
  delay(200);
}
