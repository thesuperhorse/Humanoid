#include "lx-16a_serial.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
}

#define ID1   1
#define ID2   2

void loop() {
  // put your main code here, to run repeatedly:
  LobotSerialServoMove(Serial, ID1, 100, 500);
  LobotSerialServoMove(Serial, ID2, 500, 500);
  delay(1000);
  LobotSerialServoMove(Serial, ID1, 500, 500);
  LobotSerialServoMove(Serial, ID2, 600, 500);
  delay(1000);
  LobotSerialServoMove(Serial, ID1, 900, 500);
  LobotSerialServoMove(Serial, ID2, 700, 500);
  delay(1000);
  LobotSerialServoMove(Serial, ID1, 500, 500);
  LobotSerialServoMove(Serial, ID2, 600, 500);
  delay(1000);
}
