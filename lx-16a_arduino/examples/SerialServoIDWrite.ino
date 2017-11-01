#include "lx-16a_serial.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Baud rate is 115200
  pinMode(13, OUTPUT);
  delay(1000);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(13,HIGH);  //Indicator  run indication
  LobotSerialServoSetID(Serial, 254, 1); // The first parameter is the serial port which is used for communication. The second parameter is old ID ( the number of old ID is 254 , which is valid for all online servo when you send commands to them) 
                                           //The third parameter is new ID
  delay(500);
  digitalWrite(13,LOW);
}
