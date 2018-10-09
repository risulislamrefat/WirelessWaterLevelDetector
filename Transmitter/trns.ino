#include <RCSwitch.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(12,13);
RCSwitch mySwitch = RCSwitch();

int i;

void setup() {
  mySwitch.enableTransmit(10);  
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
Serial.println(ultrasonic.distanceRead(CM));
mySwitch.send(ultrasonic.distanceRead(CM), 24); 

   /* mySwitch.switchOn("11001", "01010");

  // Wait a second

  
  // Switch off
  mySwitch.switchOff("11001", "01010");*/
  delay(10);
}
