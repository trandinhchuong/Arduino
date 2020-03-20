/* * Uses MIFARE RFID card using RFID-RC522 reader
 * Uses MFRC522 - Library
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/


#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN A0 



MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(LED_PIN, OUTPUT);

  Serial.println("cho quet the...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  String data_ID = "";
  for (byte i = 0; i < 4; i++) {
    data_ID +=
      (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i != 3 ? ":" : "");
  }

  data_ID.toUpperCase();
  Serial.print("ma the: ");
  Serial.println(data_ID);
  delay(500);

  if (data_ID.indexOf("EA:CE:AB:1A") >= 0){  //put your own tap card key;
    Serial.println("********************");
    Serial.println("**dung ma**");
    Serial.println("********************");
    digitalWrite(LED_PIN, HIGH);
    delay (500);
    digitalWrite(LED_PIN, LOW);
  }
  else {
    Serial.println("****************");
    Serial.println("**sai ma**");
    Serial.println("****************");
    digitalWrite(LED_PIN, HIGH);
    delay (500);
    digitalWrite(LED_PIN, LOW);

  }
  
}
