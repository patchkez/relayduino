!!! Arduino nano
# Windows


Paste following text at end of:
c:\Users\X\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.21\boards.txt

```
atmega328o.name=Optiboot Nano328
atmega328o.upload.tool=avrdude
atmega328o.upload.protocol=arduino
atmega328o.upload.maximum_size=32256
atmega328o.upload.speed=115200
atmega328o.bootloader.tool=avrdude
atmega328o.bootloader.low_fuses=0xff
atmega328o.bootloader.high_fuses=0xde
atmega328o.bootloader.extended_fuses=0x05
atmega328o.bootloader.path=optiboot
atmega328o.bootloader.file=optiboot/optiboot_atmega328.hex 
atmega328o.bootloader.unlock_bits=0x3F
atmega328o.bootloader.lock_bits=0x0F
atmega328o.build.mcu=atmega328p
atmega328o.build.f_cpu=16000000L
atmega328o.build.board=AVR_ATMEGA328O
atmega328o.build.core=arduino:arduino
atmega328o.build.variant=arduino:eightanaloginputs
```

... then reflash bootloader. Then use board as "Optiboot Nano328".

# Linux
## Use Arduino UNO as programmer to flash bootloader on Nano
```
cd ./code
```

Connect only USB cable to UNO and flash ArduinoISP sketch to it:
```
platformio run --target upload -e arduinoisp
```

Now connect UNO/Nano according this [document](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP).

Burn optiboot firmware to Nano:

```
platformio run --target bootloader -e uno_as_isp_to_nano -vvv
```

If you will get error like this:
```
avrdude: Device signature = 0x000000
avrdude: Yikes!  Invalid device signature.
         Double check connections and try again, or use -F to override
         this check.
```
, make sure you have capacitor between RST and GND.

## Build and Upload relayduino code into nano
Input board:
```
platformio run --target upload -e nano_input
```
Output board:
```
platformio run --target upload -e nano_output
```
