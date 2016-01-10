
#define LMF 6 //LeftMotorForward
#define LMB 5
#define RMF 8 
#define RMB 9  

void setup() {
 Serial.begin(9600); 
 pinMode(LMF, OUTPUT);
 pinMode(LMB, OUTPUT);
 pinMode(RMF, OUTPUT);
 pinMode(RMB, OUTPUT);
 Serial.println("Connection Succesfull");

}

void loop() {
 if(Serial.available() > 0) {
  int data = Serial.read(); 
  switch(data){
    case 'm' : moveForward(); break;
    case 'a' : moveBackward();break; 
    default : break; 
  }
  delay (50); 
 }

 void moveForward(){
  Serial.println("moveForward"); 
  digitalWrite(LMB,LOW);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMB,LOW);
  digitalWrite(RMF, HIGH);
 }

}
