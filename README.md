# DRV2605L Haptic Controller Data Sheet Info
https://www.ti.com/lit/ds/symlink/drv2605l.pdf
## I2C
* Slave address: 0x5A (0xB4 read and 0xB5 write)
* Most significant bit (MSB) first
* Use external pull-up resistors for SDA and SCL with values between 660 Ohm and 4.7 kOhm (I used 4.7)

## Important Register Addresses
### Mode --> 0x01
Bits 0-2 control the device mode. Bit 6 controls software standby mode, and bit 7 controls the device reset.
### Real-Time Playback --> 0x02 
Allows the user to set an aplitude value from 0x01 to 0xFF for continuous haptic playback. Can also be set up with PWM.
### Waveform Sequencer --> 0x04 - 0x0B
The DRV2605 comes with a built in ROM library of waveforms, which translate to various haptic effects. There are 123 total effects. The sequencer has 8 different addresses, allowing the user to chain up to 8 different effects together, with a delay between them if bit 7 is set. While a comprehensive list of effects is not included with the datasheet (which is very annoying), I found a source with the full list (on page 15):
https://www.digikey.fr/htmldatasheets/production/1801148/0/0/1/DRV2605-Haptic-Controller-Breakout.pdf
### GO --> 0x0C
This register begins any processes set by the Mode register. Only bit 0 is used. Setting it to 1 will begin a process, and setting it to 0 will stop a process.
### Rated Voltage --> 0x16
Bits 0-7 control the reference voltage used in closed-loop operation.
### Overdrive Clamp Voltage --> 0x17
This bounds the overdrive voltage, which can go above the rated voltage in some situations during closed-loop operation. 
### Control Registers --> 0x1B - 0x1F
These five registers control a variety of settings, as the name suggests. Many of these settings are fine left on default and are only used in specific scenarios. A full summary of the settings can be found in the datasheet.

----
There are many other registers that have specific use cases that I did not use. However, one of the more interesting features that I noticed was the audio-to-vibe. Using registers 0x11 to 0x15, you can set up the sensor to give meaningful haptic feedback to match an audio input. Unfortunately, you need a seperate audio sensor or microphone, but given more time I think this would be an interesting feature to mess around with. 