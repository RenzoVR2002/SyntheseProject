# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1
bestel alle componenten uit de bill of materials  
### stap 2
Soldeer pinnen om de breakout boards van de sensoren en de H-brug
### stap 3
Check adhv de proof of concepts of de hardware in orde is
### stap 4
Soldeer dupondraadjes aan de draadjes van de batterijhouder
### stap 5
plak de motoren adhv dubbelzijdige plakband aan de onderkant van het plexiglas op zo'n 2 cm van de achterkant en bevestig de wielen op de assen van de motoren
### stap 6
plak het breadboard op de bovenkant van het plexiglas op zo'n halve centimeter van de achterkant
### stap 7
plak de zijkant van de batterijhouder op het breadboard ongeveer boven de motoren
### stap 8
plak het plastieken hulpstukje vooraan aan de onderkant van het plexiglas en laat het de helft uitsteken tot voorbij de voorkant van het plexiglas
### stap 9
plak de breakoutboard van de sensor zodanig op het hulpstukje dat de sensoren zo'n 2 à 3 mm van de grond hangen.
### stap 10
plak de arduino leonardo op de achterkant van de batterijhouder
### stap 11
plaats de H-brug vooraan op het breadboard en Verbind adhv het elektrisch schema alle componenten met dupondraadjes
### stap 12
Verbind nu bekabeld met de arduino leonardo en upload het arduino bestand Cyclus.ino dat je kan vinden in deze github bij code-> basis. En zorg ervoor dat de bibliotheken included zijn in het bestand. ( zet eerst de 4 bestanden in 1 mapje en open dan pas het arduinobestand).
### stap 13
Open de Seriele Monitor en bekijk de waarden. Plaats de sensoren op een witte ondergrond en typ in de seriele monitor "calibrate white". Plaats de sensoren op een zwarte ondergrond en typ in de seriele monitor "calibrate black"
### stap 14
Open nu het bestand Finale_Code.ino dat je kan vinden bij code-> finaal, Maar Verander op regel 45 digitalWrite(Standby,1) naar digitalWrite(Standby,0) 
Upload na deze aanpassingen het bestand bekabeld naar de arduino
### stap 15
Open de seriele monitor en zet de sensoren op een witte ondergrond. Typ in de seriele monitor "calibrate white" tot de waardes zodicht mogelijk bij 1000 komen te liggen en zet de sensoren op een zwarte ondergrond. Typ in de seriele monitor "calibrate black" tot de waardes zodicht mogelijk bij 0 komen te liggen
### stap 16
Verander op regel 45 digitalWrite(Standby,0) terug naar digitalWrite(Standby,1) en Upload het bestand naar de Arduino en voer volgende commandos in in de seriele monitor
set power 200
set diff 0.5
set kp 15
set cycle time 8000 
### stap 17
Ontkoppel de Arduino nu met je pc 
### stap 18 
Steek de batterijen in de batterijhouder 
### stap 19 
Zet de robot op het parcours 
