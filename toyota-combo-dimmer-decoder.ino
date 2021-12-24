#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 17;

mcp2515_can CAN(SPI_CS_PIN);

char len = 0;
char buf[8];
unsigned long canId = 0;

void setup() {
  pinMode(A0, OUTPUT);
  CAN.begin(CAN_500KBPS);

  // the library is really dodgy
  // so we have to set the mask and filter multiple times
  // otherwise it has a tendency to recv random data
  delay(500);
  CAN.init_Mask(0, 0, 0x3FF);
  CAN.init_Mask(1, 0, 0x3FF);
  CAN.init_Filt(0, 0, 0x620);
  CAN.init_Filt(1, 0, 0x620);
  CAN.init_Filt(2, 0, 0x620);
  CAN.init_Filt(3, 0, 0x620);
  CAN.init_Filt(4, 0, 0x620);
  CAN.init_Filt(5, 0, 0x620);

  delay(500);
  CAN.init_Mask(0, 0, 0x3FF);
  CAN.init_Mask(1, 0, 0x3FF);
  CAN.init_Filt(0, 0, 0x620);
  CAN.init_Filt(1, 0, 0x620);
  CAN.init_Filt(2, 0, 0x620);
  CAN.init_Filt(3, 0, 0x620);
  CAN.init_Filt(4, 0, 0x620);
  CAN.init_Filt(5, 0, 0x620);

  delay(500);
  CAN.init_Mask(0, 0, 0x3FF);
  CAN.init_Mask(1, 0, 0x3FF);
  CAN.init_Filt(0, 0, 0x620);
  CAN.init_Filt(1, 0, 0x620);
  CAN.init_Filt(2, 0, 0x620);
  CAN.init_Filt(3, 0, 0x620);
  CAN.init_Filt(4, 0, 0x620);
  CAN.init_Filt(5, 0, 0x620);
}

void loop() {
  CAN.readMsgBuf(&len, buf);
  canId = CAN.getCanId();

  if ((canId = 1568) && (bitRead(buf[4], 6) == 1)) {
    digitalWrite(A0, HIGH);
  }
  if ((canId = 1568) && (bitRead(buf[4], 6) == 0)) {
    digitalWrite(A0, LOW);
  }

  delay(20);
}
