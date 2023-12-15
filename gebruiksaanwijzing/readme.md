# Gebruiksaanwijzing

### opladen / vervangen batterijen
De Li-Ion batterijen zijn simpel op te laden met een oplaadstation
Dat kan adhv van onderstaand voorbeeld.
https://www.bol.com/nl/nl/p/kimo-direct-batterijoplader-complete-set-lader-3-lithium-li-ion-18650-batterijen-power-charger-universeel-aa-aaa-18500-18650-etc-compatibel-met-vele-rechargeable-batteries-10440-14500-16340-16650-18350-18500-18650-26650/9300000003344982/

### draadloze communicatie
#### verbinding maken
Er is geen draadloze communicatie voorzien. Om te communiceren met de robot moet je de arduino gekabeld verbinden met je pc.

#### commando's
debug 
set cycle [µs]  
set power [0..255]  
set diff [0..1]  
set kp [0..]   
calibrate black  
calibrate white  

### settings
De robot rijdt stabiel met volgende parameters:
cycle : 8000
Diff : 0.5
kp : 12
power 200                     
### start/stop button
Er is geen Start/Stop Button aanwezig. Om de robot te  stoppen kan je wel het dupondraadje op de rode kabel van de batterijhouder uit het breadboard trekken. 
