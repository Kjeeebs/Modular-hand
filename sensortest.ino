/*

*/

#include <SharpDistSensor.h>

// Define the number of sensors in the array as a constant
const byte nbSensors = 3;

// Window size of the median filter (odd number, 1 = no filtering)
const byte medianFilterWindowSize = 5;

// Define the array of SharpDistSensor objects
SharpDistSensor sensorArray[] = {
  SharpDistSensor(A3, medianFilterWindowSize), // First sensor using pin A1 left
  SharpDistSensor(A2, medianFilterWindowSize), // Second sensor using pin A2 middle
  SharpDistSensor(A0, medianFilterWindowSize), //right sensor
  
  // Add as many sensors as required
};
uint16_t distArray[nbSensors];




  
void setup() {
  Serial.begin(9600);
  // Set some parameters for each sensor in array
  for (byte i = 0; i < nbSensors; i++) {
    sensorArray[i].setModel(SharpDistSensor::GP2Y0A51SK0F_5V_DS);  // Set sensor model
    // Set other parameters as required
  }
}

void loop() {
  // Read distance for each sensor in array into an array of distances
  for (byte i = 0; i < nbSensors; i++) {
    distArray[i] = sensorArray[i].getDist();
  }

  // Print distance to Serial
  Serial.print(distArray[0]);
  Serial.print("\t");
  Serial.print(distArray[1]);
  Serial.print("\t");
  Serial.print(distArray[2]);
  Serial.println();
  

  // Wait some time
  delay(50);
}
