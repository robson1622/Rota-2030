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

  // receive a message
  byte rxBuf[8];
  byte len = 0;
  unsigned long rxId = 0;
  if (CAN.checkReceive() == CAN_MSGAVAIL) {
    CAN.readMsgBuf(&len, rxBuf);
    rxId = CAN.getCanId();
    Serial.print("Message received on bus with ID ");
    Serial.print(rxId);
    Serial.print(" : ");
    float value;
    memcpy(&value, rxBuf, sizeof(value));
    Serial.println(value);
  } else {
    Serial.println("No message received");
  }

  delay(1000);
}
