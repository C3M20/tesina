#include <Maze.h>
#include <Time.h>
Maze maze; 

int FDS = 1; //Front Distance Sensor 
int LDS = 2; //Left Distance Sensor 
int RDS = 3; //Right Distance Sensor 
 
int motor_speed = 160; 
time_t curr; 
  
//Correr sin chocar con algo. Siempre empezar por la izq. 

void setup() {
  maze.init(); 
  
  Serial.begin(9600);
}

void loop() {

  curr = now();  
  moveForward(); 
  if(maze.readSensorValue(FDS) > 700 && curr > 0){ // Pared
    setTime(0);     
    delay(60);
    if(maze.readSensorValue(FDS) < 700) 
    {
      sendToPhone("L");  
      turnLeft();
    }
    else if(maze.readSensorValue(FDS) < 700) 
    {
      sendToPhone("R"); 
      turnRight();   
    }
  }
  

}
void sendToPhone( String turn){
   Serial.print("Time: ");
    Serial.print(curr); 
    Serial.print("   Distance: ");
    Serial.print(curr*motor_speed) ;
    Serial.println(turn); 
}
void moveForward(){
  maze.setMotor(1, motor_speed);
  maze.setMotor(2, motor_speed);  
}
void turnLeft(){
  maze.setMotor(1, 100); 
  maze.setMotor(2,-100); 
  delay(2550);

}
void turnRight(){
  maze.setMotor(1, -100); 
  maze.setMotor(2,100); 
  delay(2550); 
  
}
