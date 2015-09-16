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
 
 //Transmit a byte from master to slave, and simultaneously receive a byte 
 //from slave to master. SPI always transmits and receives at the same time,
 //but often the received byte is ignored. When only reception is needed, 
 //0 or 255 is transmitted to cause the reception.
 
 SPI.transfer(0); //address
 SPI.transfer(160);//value
 digitalWrite(ss, HIGH); 
 delay(del); 
}
