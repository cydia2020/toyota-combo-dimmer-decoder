# Toyota Combination Metre Dimmer Decoder
An Arduino and MCP2515 based combination metre dimmer decoder for newer Toyota and Lexus vehicles.

# Why?
Some aftermarket radios require users to hook up its dimmer wire, which essentially tells the radio to dim the display while the parking lights are ON.
This is not great as it creates a few problems
1. In some places it is required by law to use the headlight when it's raining, even during daylight time, this can make the radio / navigation display hard to read if the dimmer is linked to the parking lights.
2. The factory radio uses this signal as the dimmer, thus making the aftermarket peripherals more stock-ish.
3. This gives me a chance to learn about the MCP2515.

# Parts Required
1.  Any Arduino that is compatible with Seeed Studio’s CAN Bus Shield Library
2. MCP2515 Shield (I use the one from KeyStudio, Seeed and Sparkfun should work equally as well).
3. A 5V/12V relay.

# Hook Up Guide
1. Hook the CAN Bus pins on your radio connector up to the CAN-H and CAN-L pins on the shield
2. Hook ground to ground and 12V to 5V with a buck converter
3. Hook the relay to 12V or 5V depending on the relay
4. Hook the input of the relay to the first analogue pin of the Arduino (A1).
5. Hook the common pin of the relay to an ACC source
6. And finally hook the N/O pin of the relay to your radio's dimmer

Video demo: https://www.youtube.com/watch?v=lJLbp_uphlY
