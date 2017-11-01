#include "lx-16a_serial.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  delay(1000);
}

#define ID1   1
#define ID2   2

#define KEY1  2
#define KEY2  3
void loop() {
  // put your main code here, to run repeatedly:
  static bool run = false;
  static char step = 0;
  static char mode = 0;
  static int pos[4] = {100,200,300,400};
  static int pos1[4] = {100,200,300,400};
  uint16_t temp;
  while (1) {
    if (mode == 0)
    {
      if (run)
      {
        LobotSerialServoMove(Serial, ID1, pos[step], 500);
        LobotSerialServoMove(Serial, ID2, pos1[step++], 500);
        if (step == 4)
        {
          step = 0;
          run = false;
        }
        delay(1000);
      }
      if (!digitalRead(KEY2))
      {
        delay(10);
        if (!digitalRead(KEY2))
        {
          run = true;
          step = 0;
          delay(500);
        }
      }
      if (!digitalRead(KEY1))
      {
        delay(10);
        if (!digitalRead(KEY1))
        {
          LobotSerialServoUnload(Serial, ID1);
          LobotSerialServoUnload(Serial, ID2);
          mode = 1;
          step = 0;
          delay(500);
        }
      }
    }
    if (mode == 1)
    {
      if (!digitalRead(KEY2))
      {
        delay(10);
        if (!digitalRead(KEY2))
        {
          pos[step] = LobotSerialServoReadPosition(Serial, ID1);
          pos1[step++] = LobotSerialServoReadPosition(Serial, ID2);
          if (step == 4)
            step = 0;
          delay(500);
        }
      }
      if (!digitalRead(KEY1))
      {
        delay(10);
        if (!digitalRead(KEY1))
        {
          temp = LobotSerialServoReadPosition(Serial, ID1);
          LobotSerialServoMove(Serial, ID1, temp, 200);
          temp = LobotSerialServoReadPosition(Serial, ID2);
          LobotSerialServoMove(Serial, ID2, temp, 200);
          mode = 0;
          delay(500);
        }
      }
    }
  }
}
