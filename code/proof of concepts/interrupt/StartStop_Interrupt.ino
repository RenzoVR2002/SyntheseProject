const int SchakelaarPin = 2; 
volatile bool SchakelaarState = LOW; 
void setup() { 
  pinMode(SchakelaarPin, INPUT); 
attachInterrupt(digitalPinToInterrupt(SchakelaarPin), SchakelaarISR, CHANGE);
Serial.begin(9600); 
}

void loop() { }
void SchakelaarISR()
{ SchakelaarState = digitalRead(SchakelaarPin); 
Serial.print("Drukknop ingedrukt: ");
 Serial.println(SchakelaarState); 
}
