#include<Servo.h>

Servo servo;

int pos = 0;   
int sensor = A0;
int minPos = 0;
int maxPos = 35;

void setup(){

servo.attach(3);
Serial.begin(9600);
}
   
void loop(){
 readSensor();
}


void rotate(){
  for(pos=minPos; pos<maxPos; pos+=1){
     servo.write(pos);
     delay(10);
    
  }

}


void backRotate(){
  for(pos=maxPos; pos>minPos; pos-=1){
     servo.write(pos);
     delay(10);
  }
}

void readSensor()
{
 int sVal=analogRead(sensor);  
 
 if(sVal >= 300 && pos == 0)
 {
   Serial.println(sVal);
   Serial.println(pos);
   rotate();
 }
 else if (sVal < 300 && pos != 0){ 
     Serial.println(sVal);
     Serial.println(pos);
     backRotate();                                                                                                                                                                                                        
 }
 
 
 delay(1 );
}

