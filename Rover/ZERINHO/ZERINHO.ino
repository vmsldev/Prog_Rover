#include "AFMotor.h"

AF_DCMotor motor1(1); //Seleçao do Motor 1 tra-esq
AF_DCMotor motor2(2); //Seleçao do Motor 2 tra-dir
AF_DCMotor motor3(3); //Seleçao do Motor 3 fro-dir
AF_DCMotor motor4(4); //Seleçao do Motor 4 fro-esq

const int SENSOR0 = 30;
const int SENSOR1 = 32;
const int SENSOR2 = 34;

int VALORSENSOR0,VALORSENSOR1,VALORSENSOR2;

void setup() {
  pinMode(SENSOR0, INPUT);
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
}

void loop() { 
      motor2.setSpeed(150);
      motor2.run(FORWARD);          
      motor3.setSpeed(150);
      motor3.run(FORWARD);        

      motor1.setSpeed(150); 
      motor1.run(BACKWARD);        
      motor4.setSpeed(150); 
      motor4.run(BACKWARD);
}




