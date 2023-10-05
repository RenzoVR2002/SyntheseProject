const int Schakelaar = 2; 
int VorigeStatus = LOW; 
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50; 

void setup() {
  pinMode(Schakelaar, INPUT);
  digitalWrite(Schakelaar, HIGH);
  Serial.begin(9600);
}

void loop() {
  int Status = digitalRead(Schakelaar);

  if (Status != VorigeStatus) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (Status != VorigeStatus) {
      VorigeStatus = Status;
      
      if (Status == HIGH) {
        Serial.println("Schakelaar is aan!");
      } else {
        Serial.println("Schakelaar is uit!");
      }
    }
  }
}
