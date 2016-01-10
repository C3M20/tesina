#include <Maze.h>
Maze maze; 

int FDS = 1; //Front Distance Sensor 
int LDS = 2; //Left Distance Sensor 
int RDS = 3; //Right Distance Sensor  

//Correr sin chocar con algo. Siempre empezar por la izq. 

void setup() {
  maze.init(); 
}

void loop() {
  moveForward(); 
  if(maze.readSensorValue(FDS) > 700){ // Pared
    
    if(maze.readSensorValue(LDS) < 700) 
      turnLeft();
    else if(maze.readSensorValue(RDS) < 700) 
      turnRight();
      
  }

}


void moveForward(){
  maze.setMotor(1, 160);
  maze.setMotor(2, 160);  
}
void turnLeft(){
  maze.setMotor(1, 100); 
  maze.setMotor(2,-100); 
  delay(50);

}
void turnRight(){
  maze.setMotor(1, -100); 
  maze.setMotor(2,100); 
  delay(50); 
  
}


