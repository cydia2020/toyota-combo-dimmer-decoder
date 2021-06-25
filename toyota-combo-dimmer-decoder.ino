// for 2016 and above toyotas

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

// const int DIMMER_RELAY = 10;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600); // For debug use
  Serial.println("CAN Read - Testing receival of CAN Bus message");  
  delay(1000);

  if (Canbus.init(CANSPEED_500)) {
    Serial.println("CAN Init ok");
  } else {
    Serial.println("Can't init CAN");
  }
}

void loop(){
  tCAN message;
  if (mcp2515_check_message()) {
      if (mcp2515_get_message(&message)) {
        if (message.id == 0x620 and message.data[4] == 0xF0) {
          digitalWrite(LED_BUILTIN, HIGH);
        } else {
          digitalWrite(LED_BUILTIN, LOW);
      }
    }
  }
}
