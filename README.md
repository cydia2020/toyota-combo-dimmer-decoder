# this is deprecated, go use this https://github.com/cydia2020/toyota-can-bus-multitool

# Toyota Combination Metre Dimmer Decoder
An Arduino and MCP2515 based combination metre dimmer decoder for newer Toyota and Lexus vehicles.

# Why?
Some aftermarket head units require users to hook up the dimmer wire, the wire essentially tells the radio to dim the display while the parking lights are ON.
This is not great since it creates a few problems:
1. In some places it is required by law to use the headlight when it's raining, even during daylight time, this can make the radio / navigation display hard to read if the dimmer is linked to the parking lights.
2. The factory radio uses this signal as the dimmer, making the aftermarket peripherals more stock-ish.

This project solves these problems as the combination metre's dimmer signal is linked to either the brightness knob or the light sensor, giving user control of when to switch to night mode on their radios.

Further, on cars with automated headlights, the radio wouldn't go into dark mode unless the conditions (e.g. light sensor reading smaller than 150 and headlights are on) defined by your car's computer are met.

# Parts Required
1. Any Arduino that is compatible with Seeed Studio’s CAN Bus Shield Library.
2. MCP2515 Shield (I use the one from KeyStudio, Seeed and Sparkfun should work equally as well).
3. A 5V/12V relay.

# Hook Up Guide
1. Hook the CAN Bus pins on your driving support ECU / ADAS Camera connector up to the CAN-H and CAN-L pins on the shield.
2. Hook ground to ground, and ACC to 5V with a buck converter. (DO NOT CONNECT ACC TO YOUR ARDUINO DIRECTLY UNLESS IT IS CAPABLE OF RUNNING OFF 12V).
3. Hook the relay to 12V or 5V depending on the relay.
4. Hook the input of the relay module to the first analogue pin of the Arduino (A1).
5. Hook the common pin of the relay to an ACC source.
6. And finally hook the N/O pin of the relay to your radio's dimmer.

# If Your Signal Is On A Different Address / Byte
`CAN.init_Filt(0, 0, 0x620);` is the address filter of the code, the MCP2515 supports a few filters, you may refer to the example in Seeed's library.
`(buf[4] == 0xf0)` makes the code read the 5th byte of the address, as it counts from zero, the code use 4 instead of 5 after `buf`.

This project should be able to be adapted to other vehicle systems, e.g. automated window roll up or automated door lock.

Video demo: https://www.youtube.com/watch?v=lJLbp_uphlY
