#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  
  //rows-cols  
  lcd.begin(16,2);
  
  lcd.print("LEMUUUUR! MUUURRR!!");
}

void loop(){
  
  //cursor pos 
  lcd.setCursor(0,1);
 
  //seconds since restart
  lcd.print(millis()/1000);
}
