// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

// Modified : 25-10-2021
// by Hollanda, change to Bahasa Indonesia

#include <Wire.h>

void setup() {

  Wire.begin();

  Serial.begin(9600);
  while (!Serial);             
  Serial.println("\nI2C Scanner");
}


void loop(){
  byte error, alamat;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (alamat = 1; alamat < 127; alamat++ ){
    Wire.beginTransmission(alamat);
    error = Wire.endTransmission();

    if (error == 0)    {
      Serial.print("perangkat I2C ditemukan pada alamat 0x");
      if (alamat < 16)
        Serial.print("0");
      Serial.print(alamat, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error pada alamat 0x");
      if (alamat < 16)
        Serial.print("0");
      Serial.println(alamat, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("Tidak ada perangkat I2C yang ditemukan\n");
  else
    Serial.println("Selesai\n");

  delay(2000);           
}

