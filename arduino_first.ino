void setup() {
 pinMode(3, OUTPUT); 
 pinMode(2, OUTPUT);

}

void loop() {
 digitalWrite(3, HIGH); 
 delay (2000); 

 digitalWrite(2,HIGH);
 delay(500);

 digitalWrite(2,LOW);
 delay(1000);

}
