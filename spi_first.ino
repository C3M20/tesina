#include "SPI.h"

  int ss = 8; 
  int del = 500; 
void setup() {
pinMode(ss, OUTPUT); 
 SPI.begin();
 SPI.setBitOrder(MSBFIRST); // does the prosessor requires to be MSB?
}

void loop() {
 digitalWrite(ss, LOW); 
 SPI.transfer(0);
 SPI.transfer(160);
 digitalWrite(ss, HIGH); 
 delay(del); 
}
