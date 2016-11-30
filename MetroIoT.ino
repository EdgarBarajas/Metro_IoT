#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int stOne = 0;
int stTwo = 0;
int stLatest = 0;
int count = 0;
int indicator = 13;
int ds = 3;

int stOne1 = 0;
int stTwo1 = 0;
int stLatest1 = 0;
int count1 = 0;
int ds1 = 5;

void setup(){
  lcd.begin();
  lcd.backlight(); 
  pinMode(indicator, OUTPUT);
  pinMode(ds,INPUT);
  pinMode(ds1,INPUT);
}

void loop(){
  stOne = digitalRead(ds);
  delay(10);
  stTwo = digitalRead(ds);
  if(stOne == stTwo){
    if(stOne != stLatest){
      if(stOne == HIGH){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(count);
        lcd.print(" Personas 1");
        count = count + 1;

        lcd.setCursor(0,1);
        lcd.print(count1);
        lcd.print(" Personas 2");
      }
    }
  }
  stLatest = stOne;  

  stOne1 = digitalRead(ds1);
  delay(10);
  stTwo1 = digitalRead(ds1);
  if(stOne1 == stTwo1){
    if(stOne1 != stLatest1){
      if(stOne1 == HIGH){
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print(count1);
        lcd.print(" Personas 2");
        count1 = count1 + 1;

        lcd.setCursor(0,0);
        lcd.print(count);
        lcd.print(" Personas 1");
      }
    }
  }
  stLatest1 = stOne1;      
  if(count%2 == 0){
    digitalWrite(indicator, LOW);
  }
  else{
    digitalWrite(indicator, HIGH);
  }
}
