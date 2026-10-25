// tested code works with simple beep sound when rfid card is detected
// adding piezo hits later
#include <SPI.h>
#include <MFRC522.h>
#include <ESP_I2S.h>

#define RST_PIN D6
#define SS_PIN D5

#define I2S_BCLK 3
#define I2S_LRC 4
#define I2S_DIN 5

MFRC522 rfid(SS_PIN, RST_PIN);
I2SClass i2s;

// beep sound
void beep() {
  for (int i = 0; i < 2000; i++) {
    int16_t sample;
    if ((i / 10) % 2 == 0) {
      sample = 8000;
    } else {
      sample = -8000;
    }
    i2s.write((uint8_t*)&sample, 2);
  }
}

void setup() {
  Serial.begin(115200);

  i2s.setPins(I2S_BCLK, I2S_LRC, I2S_DIN);
  i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO);

  SPI.begin();
  rfid.PCD_Init();

  Serial.println("Ready!");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    Serial.print("Card UID: ");
    for (int i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i], HEX);
      Serial.print(" ");
    }
    Serial.println();

    beep();

    rfid.PICC_HaltA();
  }
}