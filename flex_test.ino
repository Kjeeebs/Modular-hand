


int ResMiddle  = A0;
int ResAnnular = A1;
int ResPinky   = A2;

void setup()
{
  Serial.begin(9600);   // Activating serial communication, XBee Series 1 are pre-programmed at 9600 baud/s
  
     // The variables of the sensor are set as input
  pinMode(ResMiddle,  INPUT);
  pinMode(ResAnnular, INPUT);
  pinMode(ResPinky,   INPUT);
}

void loop()
{
  Serial.println("<");      //This symbol is needed to indicate the start of the "data package".
  Serial.println(analogRead(ResMiddle ));  
  Serial.println(analogRead(ResAnnular));
  Serial.println(analogRead(ResPinky  ));
  Serial.println("---------------");
  
  delay(1000);
}
