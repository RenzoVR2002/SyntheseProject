#include "SerialCommand.h"
#include "EEPROMAnything.h"

#define SerialPort Serial
#define Baudrate 115200

#define Standby 8
#define MotorLeftForward 9
#define MotorLeftBackward 10
#define MotorRightForward 13
#define MotorRightBackward 11

SerialCommand sCmd(SerialPort);
bool debug;
unsigned long previous, calculationTime;
const int sensor[] = {A5, A4, A3, A2, A1, A0};
struct param_t
{
  unsigned long cycleTime;
  /* andere parameters die in het eeprom geheugen moeten opgeslagen worden voeg je hier toe ... */
  int black[6];
  int white[6];
  float kp ;
  float diff ;
  int power ;
} params;

void setup()
{
  SerialPort.begin(Baudrate);

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.setDefaultHandler(onUnknownCommand);
 sCmd.addCommand("calibrate",onCalibrate);
  EEPROM_readAnything(0, params);

  pinMode(13, OUTPUT);
  SerialPort.println("ready");
}

void loop()
{
  sCmd.readSerial();
 digitalWrite(Standby,1);
  unsigned long current = micros();
  if (current - previous >= params.cycleTime)
  {
    previous = current;
 long normalised[6];
SerialPort.print(" Normalised Values: ");
    for ( int i = 0; i < 6;i++)
    {
   //  SerialPort.print(analogRead(sensor[i]));
  // SerialPort.print(" ");

     long value = analogRead(sensor[i]);
      normalised[i] = map(value, params.black[i], params.white[i], 0, 1000);
      SerialPort.print(normalised[i]);
       SerialPort.print(" ");
       
    }
       SerialPort.println();

  int index = 0;
  for (int i = 1; i <6; i++) if (normalised[i] < normalised[index]) index = i;


  float Pposition;
if (index == 0) {}
else if (index == 5) {}
else
{
    int sNul = normalised[index];
    int sMinEen = normalised[index-1];
    int sPlusEen = normalised[index+1];

    float b = sPlusEen - sMinEen;
    b = b / 2;
    float a = sPlusEen - b - sNul;
    
   float position = -b / (2 * a);
   position += index;
   position -= 2.5;

   position *= 15;
  Pposition = position;
   SerialPort.print("positie: ");
   SerialPort.print(position);
}
SerialPort.println();
 SerialPort.print("Ppositie: ");
   SerialPort.print(Pposition);

float error = -Pposition;
float output = error * params.kp; 

SerialPort.println();
   SerialPort.print("error: ");
   SerialPort.print(error);
   SerialPort.println();
   
output = constrain(output, -510, 510);
int powerLeft = 0;
int powerRight = 0;
if (output >= 0)
{ 
  powerRight = constrain(params.power + params.diff *output, -255, 255);
  powerLeft = constrain(powerRight - output, -255, 255);
  powerRight = powerLeft + output;
  }
else 
{
  powerLeft = constrain(params.power - params.diff *output, -255, 255);
  powerRight = constrain(powerLeft + output, -255, 255);
  powerLeft = powerRight - output;
  }

analogWrite(MotorLeftForward, powerLeft > 0 ?  powerLeft :0);
analogWrite(MotorLeftBackward, powerLeft < 0 ? -powerLeft :0);
analogWrite(MotorRightForward, powerRight > 0 ? powerRight :0);
analogWrite(MotorRightBackward, powerRight < 0 ? -powerRight :0);
   
 SerialPort.print("output: ");
   SerialPort.print(output);
   SerialPort.println();
   SerialPort.print("PowerLeft: ");
   SerialPort.print(powerLeft);
   SerialPort.println();
   SerialPort.print("powerRight: ");
   SerialPort.print(powerRight);
   SerialPort.println();  
   
  }

  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}

void onUnknownCommand(char *command)
{
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

void onSet()
{
  char* param = sCmd.next();
  char* value = sCmd.next();  
  
  if (strcmp(param, "cycle") == 0) params.cycleTime = atol(value);
  /* parameters een nieuwe waarde geven via het set commando doe je hier ... */
   else if (strcmp(param, "power") ==0) params.power = atol(value);
  else if (strcmp(param, "diff") ==0) params.diff = atof(value);
  else if (strcmp(param, "kp") ==0) params.kp = atof(value);
  EEPROM_writeAnything(0, params);
}

void onDebug()
{
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);
  
  /* parameters weergeven met behulp van het debug commando doe je hier ... */
     SerialPort.print("black: ");
  for ( int i = 0; i < 6; i++)
  {
    SerialPort.print(params.black[i]);
    SerialPort.print(" ");
  }
  SerialPort.println(" ");

   SerialPort.print("white: ");
  for ( int i = 0; i < 6; i++)
  {
    SerialPort.print(params.white[i]);
    SerialPort.print(" ");
  }
  SerialPort.println(" ");

   SerialPort.print("power: ");
  SerialPort.println(params.power);

   SerialPort.print("diff: ");
  SerialPort.println(params.diff);

   SerialPort.print("kp: ");
  SerialPort.println(params.kp);
  
  
  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  calculationTime = 0;
}
void onCalibrate()
{
  char* param = sCmd.next();

  if (strcmp(param, "black") == 0)
  {
    SerialPort.print("start calibrating black... ");
    for (int i = 0; i < 6; i++) params.black[i]=analogRead(sensor[i]);
    SerialPort.println("done");
  }
  else if (strcmp(param, "white") == 0)
  {
    SerialPort.print("start calibrating white... ");    
    for (int i = 0; i < 6; i++) params.white[i]=analogRead(sensor[i]);  
    SerialPort.println("done");      
  }  }
