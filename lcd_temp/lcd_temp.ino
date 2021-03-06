#include <LiquidCrystal.h>
#include <DallasTemperature.h> 
#include <OneWire.h>  

#define TEMP_PIN 9


LiquidCrystal lcd(12,11,5,4,3,2);

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

void setup(){
  
  //rows-cols   
  lcd.begin(16,2);
  
  lcd.print("Temperature here");
 
  sensors.begin();
}


void loop(){
  
  lcd.setCursor(0,1);

  delay(1000);
  
  sensors.requestTemperatures(); 
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print((char)223);
  lcd.print("C");
}
