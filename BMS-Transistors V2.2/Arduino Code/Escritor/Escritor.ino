#include <mcp_can.h>
#include <SPI.h>

// define the CS pin of MCP2515
#define CAN_CS 10

// create an instance of MCP2515
MCP_CAN CAN(CAN_CS);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  // initialize the MCP2515
  if (CAN.begin(CAN_500KBPS) == CAN_OK) {
    Serial.println("MCP2515 initialized");
  } else {
    Serial.println("MCP2515 initialization failed");
    while (1) {
      ;
    }
  }
}

void loop() {
  // send a message with ID 0x123 and data [1.23, 4.56]
  float data[] = {1.23, 4.56};
  byte len = sizeof(data);
  byte buf[len];
  memcpy(buf, &data, len);
  CAN.sendMsgBuf(0x123, 0, len, buf);

  delay(1000);
}
