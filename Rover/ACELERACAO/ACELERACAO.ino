#include "AFMotor.h"

AF_DCMotor motor1(1); //Seleçao do Motor 1 tra-esq
AF_DCMotor motor2(2); //Seleçao do Motor 2 tra-dir
AF_DCMotor motor3(3); //Seleçao do Motor 3 fro-dir
AF_DCMotor motor4(4); //Seleçao do Motor 4 fro-esq

const int SENSOR0 = 42;
const int SENSOR1 = 34;
const int SENSOR2 = 32;

int VALORSENSOR0,VALORSENSOR1,VALORSENSOR2;

void setup() {
  pinMode(SENSOR0, INPUT);
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
}

void mover_frente(int velocidade)
{
  while(VALORSENSOR0==HIGH && VALORSENSOR1==LOW && VALORSENSOR2==HIGH){
      velocidade=velocidade+1; //acelerando de 1 em 1
      if(velocidade==255){
        velocidade=254;
      }
      motor1.setSpeed(velocidade);
      motor1.run(FORWARD);        
      motor2.setSpeed(velocidade);
      motor2.run(FORWARD);        
      motor3.setSpeed(velocidade);
      motor3.run(FORWARD);       
      motor4.setSpeed(velocidade);
      motor4.run(FORWARD);     
  }      
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
  //1ºIF gira sentido horario mais lentamente
  if(VALORSENSOR0==HIGH && VALORSENSOR1==LOW && VALORSENSOR2==LOW){
  while(VALORSENSOR0==HIGH && VALORSENSOR1==LOW && VALORSENSOR2==LOW){
  esq=esq+3;
  dir=dir+1;
  if(esq>=235 || dir>=150){
    esq=255;
    dir=150;
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
  }
  //2ºIF gira sentido horario mais rapidamente
if(VALORSENSOR0==HIGH && VALORSENSOR1==HIGH && VALORSENSOR2==LOW){
  while(VALORSENSOR0==HIGH && VALORSENSOR1==HIGH && VALORSENSOR2==LOW){
  esq=esq+5;
  dir=dir+1;
  if(esq>=235 || dir>=50){
    esq=255;
    dir=50;}
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
}


void mover_esquerda(int esq,int dir)
{
  //1ºIF gira sentido antihorario mais lentamente
  if(VALORSENSOR0==LOW && VALORSENSOR1==LOW && VALORSENSOR2==HIGH){
  while(VALORSENSOR0==LOW && VALORSENSOR1==LOW && VALORSENSOR2==HIGH){
  esq=esq+1;
  dir=dir+3;
  if(esq>=150 || dir>=235){
    esq=150;
    dir=255;
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
      //2ºIF gira sentido antihorario mais rapidamente
  if(VALORSENSOR0==LOW && VALORSENSOR1==HIGH && VALORSENSOR2==HIGH){
  while(VALORSENSOR0==LOW && VALORSENSOR1==HIGH && VALORSENSOR2==HIGH){
  esq=esq+1;
  dir=dir+5;
  if(esq>=50 || dir>=235){
    esq=50;
    dir=255;
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
      mover_frente(0);
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
    mover_tras(100);
  }
    else
  if(VALORSENSOR0==LOW && VALORSENSOR1==LOW && VALORSENSOR2==LOW) //parar (e=1,c=1,d=1)
      parar();
}
