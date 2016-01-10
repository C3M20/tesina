int led = 13;
int tx = 10;
int rx = 11; 
char inSerial[15];


void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, OUTPUT);
  offAll();
}

void loop(){

  int i = 0;
  int m = 0; 
  delay(500);
  if(Serial.available() > 0){
    while(Serial.available() > 0 ){
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    Check_Protocol(inSerial);
  }
}

void offAll() {
  digitalWrite(led, HIGH);
}

void Check_Protocol(char inStr[]){
  int i = 0; 
  int m = 0; 
  Serial.println(inStr);

  if(!strcmp(inStr,"on")) {
    digitalWrite(led, LOW); 
    Serial.println("Led ON"); 
    for(m = 0; m<11; m++){
      inStr[m]=0;}
      i=0;
    }

  if(!strcmp(inStr,"off")) {
    digitalWrite(led, HIGH); 
    Serial.println("Led OFF"); 
    for(m = 0; m<11; m++){
      inStr[m]=0;}
      i=0;
    }
  else {
    for(m = 0; m<11; m++){
      inStr[m]=0;
      }
      i=0;   
  }
}

