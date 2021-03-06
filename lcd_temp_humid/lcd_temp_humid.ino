#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;
#define DHT_PIN 9


LiquidCrystal lcd(12,11,5,4,3,2);


void setup(){
  
  //rows-cols   
  lcd.begin(16,2);
 
}


void loop(){
  
  int chk = DHT.read11(DHT_PIN);
   delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  
}
