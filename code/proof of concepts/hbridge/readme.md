# H-Bridge proof of concept

minimale hard- & software die aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting.


const int STBY = 8;
const int AIN1 = 9;
const int AIN2 = 10;
const int BIN1 = 2;
const int BIN2 = 3;

void setup() {
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  digitalWrite(STBY, HIGH); // Zet de DRV8833 in actieve modus
}

void loop() {
  // Motor A vooruit
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  // Motor B achteruit
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);

  delay(2000); // Wacht 2 seconden

  // Stop beide motoren
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  delay(2000); // Wacht 2 seconden

  // Motor A achteruit
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);

  // Motor B vooruit
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  delay(2000); // Wacht 2 seconden

  // Stop beide motoren
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  delay(2000); // Wacht 2 seconden
}

Dit is een eenvoudig programma om motor A en motor B afzonderlijk aan te sturen en de draairichting te regelen. U kunt de snelheid aanpassen door PWM (pulsbreedtemodulatie) te gebruiken op de AIN1- en BIN1-pinnen.
