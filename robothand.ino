

#include <Servo.h>   // Library needed to use function for servomotors
#include <SoftwareSerial.h>
SoftwareSerial Master(1,2);

Servo ServoFinger1, ServoFinger2,        // Assigns the six  servos
ServoFinger3,ServoFinger1_2,ServoFinger2_2,ServoFinger3_2;

byte startPackage; // Variable that will contain the character of start package set in the Styrehanske sketch, "<" 

int AngFinger1   = 0;   // Variables with the values for the servomotors (between 0 and 180)
int AngFinger2   = 0;
int AngFinger3   = 0;



void setup()
{
  Serial.begin(9600);      // Serial communication is activated at 9600 baud/s.
  SUART.begin(9600);
  
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
    AngFinger1   = Master.read();       
    AngFinger2   = Master.read();       
    AngFinger3   = Master.read();
    
    
    if(startPackage == '<'){   // Verifying that the first value is "<"
    
      if(AngFinger1!=255)  // Sometimes the incoming value goes to 255, I couldn't discover yet the reason, so I simply excluded it when it happens. You can remove this line for every finger if you don't have this kind of problem
      ServoFinger1.write(AngFinger1);  // The servomotors rotates of the assigned degrees
                                                    
      if(AngFinger2!=255)
      ServoFinger2.write(AngFinger2);
    
      if(AngFinger3!=255)
      ServoFinger3.write(AngFinger3);
    
         
    }
  }
  delay(30); // a delay to make the servomotors working correctly (a lower value could make the system not working, higher value make it slower)
}            
