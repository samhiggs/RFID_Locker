/*
  RFID CARD READER V1
  6:54pm 19.09.17
  Author: Sam Higgs
  This program provides RFID access control
  It reads an RFID card
  determines whether the RFID card has the appropriate permissions
  Either authorises or denies access.  
*/
#include <eeprom.h>
#include <spi.h>  //RC522 modules protocol
#include <mfrc522.h>

#define SS_PIN 10;
#define RST_PIN 9;

//Create global Variables
boolean match = fales;
boolean programMode = false;
int successRead;
int sizeOfCard = 4;
byte storedCard[sizeOfCard];
byte readCard[sizeOfCard];
byte masterCard[sizeOfCard];
MFRC522 mfrc522(SS_PIN, RST_PIN); //creates an MRFC522 object
  
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mrfc522.PCD_Init();
  mrfc522.PCD_SetAntennaGain(mfrc.RxGain_max);
  if(EEPROM.read(1) != 1) {
	Serial.println("No Master Card Defined");
	Serial.println("Please scan Master Card");
	do {
	  successRead = getID();
	} while (!successRead);
	for(int i = 0;i < sizeOfCard;++i) {
	  EEPROM.write(2+i,readCard[i]);
	}
	EEPROM.write(1,1); //Define mastercard
	Serial.println("Master Card Stored");
  }
  Serial.println("Master Card's UID: ");
  for (int i = 0; i < sizeOfCard; ++i)
  {
	masterCard[i] = EEPROM.read(2+i); //Store mastercard uid in local mem
	Serial.print(masterCard[i].HEX);
  }
  Serial.println("\nPlease Scan your ID");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Swipe your card");
  //*********Clean this up************
  //Use ISR
  while(!successRead){
	successRead = getID();
  }
  if(programMode) {
  	if(isMaster(readCard)){
  		Serial.println("Exiting Program Mode");
  		Serial.println("MASTERCARD MODE");
  		programMode = false;
  	}
  }


}

int getID() {
  int id = 0;
  return id;
}

int isMaster(byte[sizeOfCard] card) {
	int isMaster = 0;
	return isMaster;
}
