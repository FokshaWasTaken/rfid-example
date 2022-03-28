# rfid-example
This example uses the RFID technology to make a Micro Servo turn with the help of an Arduino Uno.


# Parts used

- Arduino Uno
- Tower Pro Micro Servo 9g SG90
- RFID-RC522

# The wiring to the Arduino for the RFID reader

SDA------------------------Digital 10

SCK------------------------Digital 13

MOSI----------------------Digital 11

MISO----------------------Digital 12

IRQ------------------------ don't connect

GND-----------------------GND

RST------------------------Digital 9

3.3V------------------------3.3V (DO NOT CONNECT TO 5V)

# The wiring for the Micro Servo

Red wire--------5V
Brown wire-------Ground
Orange Wire----- Digital 7

# How to use

Download this library for Arduino IDE and include it https://github.com/AritroMukherjee/RFID

To find your RFID card's UID, go to File -> Examples -> MFRC522 -> DumpInfo, after that open the Serial Monitor, bring the RFID card to the reader and wait until all of the information is displayed.
You should see your Card UID, write it down/save it.

Open the Sketch file provided here, and change the UID and upload the code.
If all goes smoothly, this should work.
