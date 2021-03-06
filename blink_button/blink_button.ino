
int led = 7;
int button = 2;
int btnState = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(button,INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
   btnState = digitalRead(button);
   Serial.println(btnState);
   if (btnState == HIGH){
       digitalWrite(led,HIGH);
   } else {
       digitalWrite(led,LOW);
   }
}
