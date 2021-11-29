/*
SparkFun Inventor’s Kit
Circuit 3A-Servo

Move a servo attached to pin 9 so that it's angle matches a potentiometer attached to A0.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
 */

#include <Servo.h>          //include the servo library

int potPosition;           //this variable will store the position of the potentiometer
int servoPosition;         //the servo will move to this position

Servo myservo;              //create a servo object

void setup() {

  myservo.attach(9);        //tell the servo object that its servo is plugged into pin 9
  
}

void loop() {

  potPosition = analogRead(A0);                     //use analog read to measure the position of the potentiometer (0-1023)
  
  servoPosition = map(potPosition, 1023,0,10,170);  //convert the potentiometer number to a servo position from 20-160
                                                    //Note: its best to avoid driving the little SIK servos all the 
                                                    //way to 0 or 180 degrees it can cause the motor to jitter, which is bad for the servo.
  
  myservo.write(servoPosition);
  
                    
}

void SetServopot(int angledangle){
  if (170 > angledangle && angledangle > 10)     //setter vinkel range for servoen
  {
    myservo.write(angledangle);
  }
  else if (angledangle < 10)
  {
    angle = 10;
    myservo.write(angledangle);
  }
  else if (angledangle >170
  {
    angledangle =170;
    myservo.write(angledangle);
    
  }
}
void PrintAngledongle(Servo myservo)     // Function that rints the servos position to serialprint
{
 Serial.println( myservo.read());
}
