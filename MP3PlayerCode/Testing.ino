
#include <Adafruit_SSD1306.h>
#include "DFRobotDFPlayerMini.h"
#include "ScreenFunction.h"

//defines the buttons
boolean LeftButton;
boolean RightButton;
boolean UpButton;
boolean DownButton;

int index = 0;
boolean toggle = true;
boolean newToggle=false;

int buffer = 50; // buffer in case the two button presses have to register

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

DFRobotDFPlayerMini myDFPlayer; //declare the DFPlayer itself



#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
#define FPSerial softSerial


void TitleScreen(Adafruit_SSD1306 display){
  
  display.clearDisplay();

  display.setTextColor(1);
  display.setTextWrap(false);

  display.setCursor(7, 54);
  display.print("Player");

  display.setCursor(24, 27);
  display.print("MP3");

  display.display();

}

void MainScreen(Adafruit_SSD1306 display){

  display.clearDisplay();

  display.setTextColor(1);
  display.setTextWrap(false);
  display.setCursor(3, 14);
  display.print("Now Playing:");

  display.setCursor(2, 35);
  display.print("SONG111");




  display.display();

}


void UpdateScreen(Adafruit_SSD1306 display, int index, boolean UpButton,boolean DownButton,boolean LeftButton, boolean RightButton) {
  display.clearDisplay();
  if (RightButton && DownButton){ //Plays a track, 
    myDFPlayer.next();
    index++;
    delay(buffer);

  }

  if (RightButton && DownButton){ //Pressing  right and left = Volume goes up
    myDFPlayer.volumeUp();
    delay(buffer);
  }

  if (LeftButton && !(UpButton)){
    myDFPlayer.previous();
    delay(buffer);
  }

  if (RightButton && UpButton){
    myDFPlayer.volumeDown();
    delay(buffer);
  }
    // toggling
  if (UpButton){
    if (toggle =! newToggle){
      myDFPlayer.stop(); 
      newToggle = toggle;     
    }

    else{
      myDFPlayer.play();
      newToggle = false;
    }
  }


  display.setTextColor(1);
  display.setTextWrap(false);
  display.setCursor(3, 14);

  display.print("Now Playing:");
  display.print(index);
  display.println( "/30");
}






void setup() { 
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  Serial.begin(115200);

  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);     
  display.display();
  
  
  delay(1000);

  TitleScreen(display);
  
  delay(1000);
  
  MainScreen(display);

  delay(1000);

  pinMode(9, INPUT);
  pinMode(7, INPUT);
  pinMode(5, INPUT);
  pinMode(3, INPUT);

  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(3, HIGH);


  delay(400);
  int index = 0;
  Serial.println(F("this should work somehow")); 
  toggle = false;
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
}




void loop() {

  UpButton = (digitalRead(9) == HIGH);
  LeftButton = (digitalRead(7) == HIGH);
  DownButton = (digitalRead(5) == HIGH);
  RightButton = (digitalRead(3) == HIGH);

  if (!(UpButton)){
    Serial.println(F("Up Button"));
  }
  if (!(DownButton)){

    Serial.println(F("Down"));
  }
  if (!(LeftButton)){
    Serial.println(F("Left"));

  }
  if (!(RightButton)){
    Serial.println(F("Right"));
    
  }


  
    

  //Serial.println(!(UpButton) + !(DownButton) + !(LeftButton) + !(RightButton));
  //UpdateScreen(display, index, !(UpButton), !(DownButton), !(LeftButton), !(RightButton));

}






























void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  
}
