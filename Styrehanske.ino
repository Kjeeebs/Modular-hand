#include <SoftwareSerial.h>
SoftwareSerial SUART(9,10); //Rx and tx



int ResFinger1   = A0;  // Variables of the analog read form the flex sensors connected to the analog pins of Arduino LilyPad
int ResFinger2   = A1;  
int ResFinger3   = A2;

int VibFinger1 = 3; //Pins for the vibrators
int VibFinger2 = 4;
int Vibfinger3 = 5;

byte startPackage2;

int OpenedFinger1   =0; // Variables of the values when the hand is completely opened
int OpenedFinger2   =0; // This is needed for a continuous calibration
int OpenedFinger3   =0;


int ClosedFinger1;      // Variables of the values when the hand is completely closed
int ClosedFinger2;      // We can't set it to zero since that the minimum value reached
int ClosedFinger3;      // in the analog read never reach zero. We'll assign the value of
// a first analog read, then the program in the loop will automatically  assing lower values

int Finger1_1   =0;       // Variables of the values to send
int Finger2_1   =0;
int Finger3_1   =0;
int Finger1_2   =0;
int Finger2_2   =0;
int Finger3_2   =0;

int Finger1 =0; //Res sensor values
int Finger2 =0;
int Finger3 =0;
void setup()
{
  Serial.begin(9600);   // Activating serial communication, using serialsoftware.h
  SUART.begin(9600);
  
  pinMode(ResFinger1,   INPUT);   // The variables of the sensor are set as input
  pinMode(ResFinger2,   INPUT);
  pinMode(ResFinger3,   INPUT);

  

  ClosedFinger1   = analogRead(ResFinger1);
  ClosedFinger2   = analogRead(ResFinger2);  
  ClosedFinger3   = analogRead(ResFinger3); 
    
}

void loop()
{
  Finger1   = analogRead(ResFinger1);  
  Finger2   = analogRead(ResFinger2);  
  Finger3   = analogRead(ResFinger3);
  
   

  
  if(Finger1   > OpenedFinger1)   // Calibration reading and setting the maximum values. This needs you to completely open your hand a few times
  OpenedFinger1   = Finger1;
  if(Finger2   > OpenedFinger2)
  OpenedFinger2   = Finger2;
  if(Finger3  >  OpenedFinger3)
  OpenedFinger3  = Finger3;
  
  
  if(Finger1   < ClosedFinger1)  // Calibration reading and setting the minimum values. This needs you to completely close your hand a few times
  ClosedFinger1   = Finger1;
  if(Finger2   < ClosedFinger2)
  ClosedFinger2   = Finger2;
  if(Finger3  < ClosedFinger3)
  ClosedFinger3  = Finger3;
  
  
  Finger1_1   = map(Finger1  ,ClosedFinger1  ,OpenedFinger1  ,10,170);  // The analog read has to be readapted in values between 0 and 180 to be used by the servomotors.
  Finger2_1   = map(Finger2  ,ClosedFinger2  ,OpenedFinger2  ,10,170);  // The minimum and maximum values from the calibrations are used to correctly set the analog reads.
  Finger3_1   = map(Finger3  ,ClosedFinger3  ,OpenedFinger3  ,10,170);
  Finger1_2   = map(Finger1  ,ClosedFinger1  ,OpenedFinger1  ,0,70);
  Finger2_2   = map(Finger2  ,ClosedFinger2  ,OpenedFinger2  ,0,70);
  Finger3_2   = map(Finger3  ,ClosedFinger3  ,OpenedFinger3  ,0,70);
  
  SUART.write("<");        // This character represent the beginning of the package of the three values
  SUART.write(Finger1_1);    // The values are sent via the Tx pin (the digital pin 10)
  SUART.write(Finger2_1);  
  SUART.write(Finger3_1); 
  SUART.write(Finger1_2);
  SUART.write(Finger2_2);
  SUART.write(Finger3_2);
  
  delay(50);
  Serial.println(Finger1_1);
  
}
