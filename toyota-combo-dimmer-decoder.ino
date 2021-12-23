#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 17;

mcp2515_can CAN(SPI_CS_PIN);

bool flagRecv = 0;
char len = 0;
char buf[8];
unsigned long canId = 0;

void setup() {
  pinMode(A0, OUTPUT);
  CAN.begin(CAN_500KBPS);

  CAN.init_Mask(0, 0, 0x3FF);                         // there are 2 mask in mcp2515, you need to set both of them
  CAN.init_Mask(1, 0, 0x3FF);

  CAN.init_Filt(0, 0, 0x620);                          // there are 6 filter in mcp2515
}

void MCP2515_ISR() {
  flagRecv = 1;
}

void loop() {
  flagRecv = 0;
  CAN.readMsgBuf(&len, buf);
  canId = CAN.getCanId();

  if ((canId = 1568) && (bitRead(buf[4], 6) == 1)) {
    digitalWrite(A0, HIGH);
  } else if ((canId = 1568) && (bitRead(buf[4], 6) == 0)) {
    digitalWrite(A0, LOW);
  }

  delay(100);
}
