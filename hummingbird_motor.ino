#include <Hummingbird.h>
Hummingbird hummingbird; 
 void setup()
{  
	hummingbird.init();
 }

 void loop(){ 
  //Valor del sensor en el port 1
  Serial.println(hummingbird.readSensorValue(1));
 if(hummingbird.readSensorValue(1)>708) {
	moveRight();
	delay(500);
  }
 else {
	moveForward();
	delay(500);
	}
}


void moveForward(){
	hummingbird.setMotor(2,-255);
	hummingbird.setMotor(1,-255);
}
void moveRight(){
	hummingbird.setMotor(2,-255);
	hummingbird.setMotor(1,0);
}
