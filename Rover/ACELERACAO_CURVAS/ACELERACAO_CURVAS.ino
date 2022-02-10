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

void mover_frente(int velocidade)
{
      motor1.setSpeed(velocidade);
      motor1.run(FORWARD);        
      motor2.setSpeed(velocidade);
      motor2.run(FORWARD);        
      motor3.setSpeed(velocidade);
      motor3.run(FORWARD);       
      motor4.setSpeed(velocidade);
      motor4.run(FORWARD);     
  }      



void mover_tras(int velocidade)
{
      motor1.setSpeed(velocidade);
      motor1.run(BACKWARD);       
      motor2.setSpeed(velocidade);
      motor2.run(BACKWARD);       
      motor3.setSpeed(velocidade);
      motor3.run(BACKWARD);        
      motor4.setSpeed(velocidade);
      motor4.run(BACKWARD);        
}

void mover_direita(int esq,int dir)
{
  //1º gira sentido horario mais lentamente
  while(VALORSENSOR0==HIGH && VALORSENSOR1==LOW && VALORSENSOR2==LOW){
  delay(10);
  VALORSENSOR0 = digitalRead(SENSOR0);
  VALORSENSOR1 = digitalRead(SENSOR1);
  VALORSENSOR2 = digitalRead(SENSOR2);

  esq=esq+3;
  dir=dir+1;
  if(esq>=149 || dir>=69){
    esq=150;
    dir=70;
      }
      motor2.setSpeed(dir);
      motor2.run(FORWARD);          
      motor3.setSpeed(dir);
      motor3.run(FORWARD);        

      motor1.setSpeed(esq); 
      motor1.run(FORWARD);        
      motor4.setSpeed(esq); 
      motor4.run(FORWARD);         
}
  //2º gira sentido horario mais rapidamente
  while(VALORSENSOR0==HIGH && VALORSENSOR1==HIGH && VALORSENSOR2==LOW){
  delay(20);
  VALORSENSOR0 = digitalRead(SENSOR0);
  VALORSENSOR1 = digitalRead(SENSOR1);
  VALORSENSOR2 = digitalRead(SENSOR2);
  
  esq=esq+5;
  dir=dir+1;
  if(esq>=119 || dir>=24){
    esq=120;
    dir=25;}
      motor2.setSpeed(dir);
      motor2.run(FORWARD);          
      motor3.setSpeed(dir);
      motor3.run(FORWARD);        

      motor1.setSpeed(esq); 
      motor1.run(FORWARD);        
      motor4.setSpeed(esq); 
      motor4.run(FORWARD);
  }
}


void mover_esquerda(int esq,int dir)
{
  //1º gira sentido antihorario mais lentamente
  while(VALORSENSOR0==LOW && VALORSENSOR1==LOW && VALORSENSOR2==HIGH){
  delay(10);
  VALORSENSOR0 = digitalRead(SENSOR0);
  VALORSENSOR1 = digitalRead(SENSOR1);
  VALORSENSOR2 = digitalRead(SENSOR2);
  
  esq=esq+1;
  dir=dir+3;
  if(esq>=69 || dir>=149){
    esq=70;
    dir=150;
      }
      motor1.setSpeed(esq); 
      motor1.run(FORWARD);        
      motor4.setSpeed(esq); 
      motor4.run(FORWARD);         

      motor2.setSpeed(dir); 
      motor2.run(FORWARD);         
      motor3.setSpeed(dir); 
      motor3.run(FORWARD);      
      }
      
      //2º gira sentido antihorario mais rapidamente
  while(VALORSENSOR0==LOW && VALORSENSOR1==HIGH && VALORSENSOR2==HIGH){
  delay(20);
  VALORSENSOR0 = digitalRead(SENSOR0);
  VALORSENSOR1 = digitalRead(SENSOR1);
  VALORSENSOR2 = digitalRead(SENSOR2);
  
  esq=esq+1;
  dir=dir+5;
  if(esq>=24 || dir>=119){
    esq=25;
    dir=120;
      }
      motor1.setSpeed(esq); 
      motor1.run(FORWARD);        
      motor4.setSpeed(esq); 
      motor4.run(FORWARD);         

      motor2.setSpeed(dir); 
      motor2.run(FORWARD);         
      motor3.setSpeed(dir); 
      motor3.run(FORWARD);     
  }
}

void parar(void)
{
      motor1.setSpeed(0); 
      motor1.run(RELEASE);
      motor2.setSpeed(0); 
      motor2.run(RELEASE);
      motor3.setSpeed(0); 
      motor3.run(RELEASE);
      motor4.setSpeed(0); 
      motor4.run(RELEASE); 
}

void loop() {
  VALORSENSOR0 = digitalRead(SENSOR0);
  VALORSENSOR1 = digitalRead(SENSOR1);
  VALORSENSOR2 = digitalRead(SENSOR2);
//High=desligado=0 Low=ligado=1
//sensor0=esq sensor1=cent sensor2=dir
  if (VALORSENSOR0==HIGH && VALORSENSOR1==LOW && VALORSENSOR2==HIGH) //FrenteMax (e=0,c=1,d=0)
    {
      mover_frente(150);
     }   
   else
  if (VALORSENSOR0==LOW && VALORSENSOR1==LOW && VALORSENSOR2==HIGH) //GirarEsqMin(antihorario) (e=1,c=1,d=0)
    {
      mover_esquerda(0,0);
    }
    else
  if (VALORSENSOR0==LOW && VALORSENSOR1==HIGH && VALORSENSOR2==HIGH) //GirarEsqMax(antihorario) (e=1,c=0,d=0)
    {
      mover_esquerda(0,0);
    }
    else
  if (VALORSENSOR0==HIGH && VALORSENSOR1==LOW && VALORSENSOR2==LOW) //GirarDirMin(horario) (e=0,c=1,d=1)
  {
   mover_direita(0,0); 
   }
    else
  if (VALORSENSOR0==HIGH && VALORSENSOR1==HIGH && VALORSENSOR2==LOW) //GirarDirMax(horario) (e=0,c=0,d=1)
  {
    mover_direita(0,0);
  }
    else
  if(VALORSENSOR0==HIGH && VALORSENSOR1==HIGH && VALORSENSOR2==HIGH) //TrasMax (e=0,c=0,d=0)
  {
    mover_tras(120);
  }
    else
  if(VALORSENSOR0==LOW && VALORSENSOR1==LOW && VALORSENSOR2==LOW) //parar (e=1,c=1,d=1)
      motor2.setSpeed(100);
      motor2.run(FORWARD);          
      motor3.setSpeed(100);
      motor3.run(FORWARD);        

      motor1.setSpeed(0); 
      motor1.run(FORWARD);        
      motor4.setSpeed(0); 
      motor4.run(FORWARD);
}




