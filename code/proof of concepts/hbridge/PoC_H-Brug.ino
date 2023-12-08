const int STBY = 8;
const int AIN1 = 9;
const int AIN2 = 10;
const int BIN1 = 11;
const int BIN2 = 13;

void setup() {
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  digitalWrite(STBY, HIGH); // Zet de DRV8833 in actieve modus
}

void loop() {
 for(int i=0;i<255;i++){
     // Motor A vooruit
  analogWrite(AIN1, i); // Gebruik verschillende waarden tussen 0 en 255
 

  
  analogWrite(BIN1, i); // Gebruik verschillende waarden tussen 0 en 255
delay(100);
  }
 delay(1000);
for (int o=255;o>=0;o--){
   
  analogWrite(AIN1, o); // Gebruik verschillende waarden tussen 0 en 255

  
  analogWrite(BIN1, o); // Gebruik verschillende waarden tussen 0 en 255
delay(100);
  }
  delay(000);
for(int p=0;p<254;p++){
   // Gebruik verschillende waarden tussen 0 en 255
analogWrite(AIN2, p);


  analogWrite(BIN2, p); // Gebruik verschillende waarden tussen 0 en 255
delay(100);
  }
 delay(1000);
for (int m=255;m>=1;m--){
   
 // Gebruik verschillende waarden tussen 0 en 255
  analogWrite(AIN2, m);

  analogWrite(BIN2, m); // Gebruik verschillende waarden tussen 0 en 255
delay(100);
  }
 delay(1000);



}
