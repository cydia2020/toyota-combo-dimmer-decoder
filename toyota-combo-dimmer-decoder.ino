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
  SERIAL_PORT_MONITOR.begin(115200);
  while (!Serial) {};
  attachInterrupt(digitalPinToInterrupt(CAN_INT_PIN), MCP2515_ISR, FALLING); // start interrupt
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
    SERIAL_PORT_MONITOR.println("CAN init fail, retry...");
    delay(100);
  }
  SERIAL_PORT_MONITOR.println("CAN init ok!");

  CAN.init_Mask(0, 0, 0x3ff);                         // there are 2 mask in mcp2515, you need to set both of them
  CAN.init_Mask(1, 0, 0x3ff);

  CAN.init_Filt(0, 0, 0x620);                          // there are 6 filter in mcp2515
}

void MCP2515_ISR() {
  flagRecv = 1;
}

void loop() {
  flagRecv = 0;
  CAN.readMsgBuf(&len, buf);

  if (CAN.getCanId() == 1568) {
   for (int i = 0; i < len; i++) {
	 if (buf[4] == 240) {
		 Serial.println("dimmed");
	 } else if (buf[4] == 208) {
		 Serial.println("bright");
	 }
   }
  }
}