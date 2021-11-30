

#include <Servo.h>   // Library needed to use function for servomotors
#include <SoftwareSerial.h>
SoftwareSerial Master(1,2);

Servo ServoFinger1_1, ServoFinger2_1,        // Assigns the six  servos
ServoFinger3_1,ServoFinger1_2,ServoFinger2_2,ServoFinger3_2;

byte startPackage; // Variable that will contain the character of start package set in the Styrehanske sketch, "<" 

int AngFinger1_1   = 0;   // Variables with the values for the servomotors (between 0 and 180)
int AngFinger2_1   = 0;
int AngFinger3_1   = 0;
int AngFinger1_2   = 0;
int AngFinger2_2   = 0;
int AngFinger3_2   = 0;



void setup()
{
  Serial.begin(9600);      // Serial communication is activated at 9600 baud/s.
  Master.begin(9600);
  
  ServoFinger1.attach(9);  // The servomotors are asigned to the pins of the Arduino UNO board.
  delay(300);              // A delay of 300ms is set for a secure connection (this can be optional)
  ServoFinger2.attach(8);   
  delay(300);
  ServoFinger3.attach(7);
  delay(300);
  ServoFinger1_2.attach(6);
  delay(300);
  ServoFinger2_2.attach(5);
  delay(300);
  ServoFinger3_2.attach(4);
  delay(300);
  
  Master.println("Ready to receive."); 
}

void loop()
{ 
  if(Master.available()) {    // Waiting for data incoming from the other Arduino module
    
    startPackage = Master.read(); // The first value will be "<", the other are assigned to the finger
    AngFinger1_1   = Master.read();       
    AngFinger2_1   = Master.read();       
    AngFinger3_1   = Master.read();
    AngFinger1_2   = Master.read();
    AngFinger2_2   = Master.read();
    AngFinger3_2   = Master.read();
    
    if(startPackage == '<'){   // Verifying that the first value is "<"
    
      if(AngFinger1_1!=255)  // Sometimes the incoming value goes to 255, I couldn't discover yet the reason, so I simply excluded it when it happens. You can remove this line for every finger if you don't have this kind of problem
      ServoFinger1.write(AngFinger1_1);  // The servomotors rotates of the assigned degrees
      
      if(AngFinger1_2!=255)
        ServoFinger1_2.write(AngFinger1_2)
        
      if(AngFinger2_1!=255)
      ServoFinger2_1.write(AngFinger2_1);
      
      if(AngFinger2_2!=255)
        ServoFinger2_2.write(AngFinger2_2);
    
      if(AngFinger3_1!=255)
        ServoFinger3_1.write(AngFinger3_1);
      
      if(AngFinger3_2!=255)
        ServoFinger3_2.write(AngFinger3_2);
      delay(30);
         
    }
    if(Master.available()){
      
      startPackage2 = Master.write(>);
      ForceSense1 = Master.write();
      ForceSense2 = Master.write();
      ForceSense3 = Master.write();
      
      delay(30);
      
    }
  
}            
