/*
 * 
 * 
 * Original RFID code by Aritro Mukherjee
 * Modified and Improved by Foksha
 * 
 * 
 **/
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


Servo servo;
int angle = 0;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Show the RFID card to the reader");
  Serial.println();
  servo.attach(7);
  servo.write(angle);
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "UID") // change the UID of the RFID card here
  {
    Serial.println("Authorized access");
    Serial.println();
    Serial.println("Opening door...");
    Serial.println();
    delay(150);
    servo.write(360);
    delay(2500);
    Serial.println("Closing door...");
    delay(2500); 
    servo.write(angle);
  }
 
 else   {
    Serial.println("Access denied");
    delay(3000);
  }
}   
