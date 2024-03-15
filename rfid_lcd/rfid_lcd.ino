#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//for connection reference
const int sda = 53, mosi = 51, miso = 50, sck = 52, rst = 6;

MFRC522 mfrc522(sda,rst);
MFRC522::MIFARE_Key key;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  for (byte i=0; i<6; i++) {
    key.keyByte[i] = 0xFF;
  }
 
}



void loop(){
  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
    } 
    
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;

  }
    
    Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
    lcd.println(mfrc522.PICC_GetTypeName(piccType));

     
    
    byte sector         = 1;
    byte blockAddr      = 4;
    byte dataBlock[]    = {
        0x01, 0x02, 0x03, 0x04, //  1,  2,   3,  4,
        0x05, 0x06, 0x07, 0x08, //  5,  6,   7,  8,
        0x09, 0x0a, 0xff, 0x0b, //  9, 10, 255, 11,
        0x0c, 0x0d, 0x0e, 0x0f  // 12, 13, 14, 15
    };
    byte trailerBlock   = 7;
    MFRC522::StatusCode status;
    byte buffer[18];
    byte size = sizeof(buffer);

    // Authenticate using key A
    lcd.print("Authenticating using key ");
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        lcd.print("Authnetication failed");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    
    status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        lcd.print(mfrc522.GetStatusCodeName(status));
    } else {
      lcd.print(status);
    }

    status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr, dataBlock, 16);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Write() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        lcd.print(mfrc522.GetStatusCodeName(status));
    }
    
    delay(1000);
    lcd.clear();
   
}
