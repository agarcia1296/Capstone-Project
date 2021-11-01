/*
 * Created by: Andrew Garcia
 * Date: Decemberer 4th, 2019
 * Project: Multi-Motor Exercise Device
 * Note: If uploading to Elegoo Arduino NANO then to upload Tools>Board>Arduino UNO must be selected because same chip is used
 * Buttons are set up using Anolog pins 0-4 and LCD screen is set up using standard pin set up seen here https://www.youtube.com/watch?v=wEbGhYjn4QI
 * Troubleshooting: If the error "arvdude" appears, dissconnect the arduino from the circuit and upload the program with the arduino not connected to any pins.
 * 
 */

#include <XBee.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial XBee(0,1);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int Level_1_Button = A0;
const int Level_2_Button = A1;
const int Level_3_Button = A2;
const int Level_4_Button = A3;
const int Level_5_Button = A4;
int moduleKnob = A5;
int moduleSelect = 0;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

void setup() {
  delay(50);
  XBee.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Select Level"); // welcoming screen
  
  pinMode(Level_1_Button, INPUT);  // initialize the pushbutton pin as an input
  pinMode(Level_2_Button, INPUT);
  pinMode(Level_3_Button, INPUT);
  pinMode(Level_4_Button, INPUT);
  pinMode(Level_5_Button, INPUT);
}

void loop() {

  buttonState1 = digitalRead(Level_1_Button);
  buttonState2 = digitalRead(Level_2_Button);
  buttonState3 = digitalRead(Level_3_Button);
  buttonState4 = digitalRead(Level_4_Button);
  buttonState5 = digitalRead(Level_5_Button);
  lcd.setCursor(0,0);
 
  if (buttonState1 == HIGH) {
    XBee.write(49);
    Serial.print("Level 1");
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Setting...");
    delay(1000);
    lcd.clear();
    lcd.print("Current Level: 1");
  } 
  else if (buttonState2 == HIGH){
    XBee.write(50);
    Serial.print("Level 2");
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Setting...");
    delay(1000);
    lcd.clear();
    lcd.print("Level 2");
    
  }
  else if (buttonState3 == HIGH){
    XBee.write(51);
    Serial.print("Level 3");
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Setting...");
    delay(1000);
    lcd.clear();
    lcd.print("Level 3");
    
  }
  else if (buttonState4 == HIGH){
    XBee.write(52);
    Serial.print("Level 4");
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Setting...");
    delay(1000);
    lcd.clear();
    lcd.print("Level 4");
    
  }
  else if (buttonState5 == HIGH){
    XBee.write(53);
    Serial.print("Level 5");
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Setting...");
    delay(1000);
    lcd.clear();
    lcd.print("Level 5");
    
  }

}
