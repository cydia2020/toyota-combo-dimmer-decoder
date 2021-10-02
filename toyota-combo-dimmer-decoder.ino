#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;

mcp2515_can CAN(SPI_CS_PIN);

unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void setup() {
  delay(2000);
  pinMode(A1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(CAN_INT_PIN), MCP2515_ISR, FALLING); // start interrupt
  CAN.begin(CAN_500KBPS);

  CAN.init_Mask(0, 0, 0x7FF);                         // there are 2 mask in mcp2515, you need to set both of them
  CAN.init_Mask(1, 0, 0x7FF);

  CAN.init_Filt(0, 0, 0x620);                          // there are 6 filter in mcp2515
}

void MCP2515_ISR() {
  flagRecv = 1;
}

void loop() {
  flagRecv = 0;
  CAN.readMsgBuf(&len, buf);

  if (bitRead(buf[4], 6) == 1) {
    digitalWrite(A1, HIGH);
  } else if (bitRead(buf[4], 6) == 0) {
    digitalWrite(A1, LOW);
  }
}
