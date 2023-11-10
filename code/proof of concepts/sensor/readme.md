# Sensoren proof of concept

minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing)

6 sensors verbinden met de 6 analage ingangen aan de Arduino Leonardo.

const int numSensors = 6; // Het aantal sensoren dat je wilt gebruiken
const int sensorPins[numSensors] = {A0, A1, A2, A3, A4, A5}; 
// De pinnen waarop de sensoren zijn aangesloten

void setup() {
  Serial.begin(9600); // Start de seriële communicatie voor debugging
}

void loop() {
  unsigned int sensorValues[numSensors];

  // Lees de waarden van alle sensoren
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Toon de ruwe sensorwaarden op de seriële monitor
  for (int i = 0; i < numSensors; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(100); // Wacht 100 milliseconden voordat je opnieuw leest
}

