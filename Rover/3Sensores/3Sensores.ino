
//3 SENSORES, Organizar as portas certas;

#include "Wire.h" 
#include "Ultrasonic.h"
#include "AFMotor.h"

AF_DCMotor motor1(1); //Seleçao do Motor 1 tra-esq
AF_DCMotor motor2(2); //Seleçao do Motor 2 tra-dir
AF_DCMotor motor3(3); //Seleçao do Motor 3 fro-dir
AF_DCMotor motor4(4); //Seleçao do Motor 4 fro-esq

HC_SR04 sensord(47,49),sensorc(42,44),sensore(39,41); //S_Direita S_Centro S_Esquerda  ->(Trig, Echo)

int distanciad,distanciac,distanciae,velocidade; //D_Direita D_Centro D_Esquerda

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void frente(int velocidade){ //APENAS ANDA RETO (MOTORES ESQ = MOTORES DIR)
      motor1.setSpeed(velocidade);
      motor1.run(FORWARD);        
      motor2.setSpeed(velocidade);
      motor2.run(FORWARD);        
      motor3.setSpeed(velocidade);
      motor3.run(FORWARD);       
      motor4.setSpeed(velocidade);
      motor4.run(FORWARD);
}

void frente_virando(int esq,int dir){ //ANDA PARA FRENTE, MAS VIRANDO AO MESMO TEMPO (MOTORES ESQ != MOTORES DIR)
      motor1.setSpeed(esq);
      motor1.run(FORWARD);        
      motor2.setSpeed(dir);
      motor2.run(FORWARD);        
      motor3.setSpeed(dir);
      motor3.run(FORWARD);       
      motor4.setSpeed(esq);
      motor4.run(FORWARD);
}

void virar_eixo(int sentido, int velocidade){ //APENAS GIRA NO PROPRIO EIXO (MOTORES ESQ e MOTORES DIR, tem sentidos opostos)
  
//SE SENTIDO = 0 GIRAR SENTIDO HORARIO DIR, SE SENTIDO = 1 GIRAR SENTIDO ANTIHORARIO ESQ;
  if (sentido == 0){
      motor2.setSpeed(velocidade);
      motor2.run(BACKWARD);          
      motor3.setSpeed(velocidade);
      motor3.run(BACKWARD);        

      motor1.setSpeed(velocidade); 
      motor1.run(FORWARD);        
      motor4.setSpeed(velocidade); 
      motor4.run(FORWARD);
      }

  else if (sentido == 1){
      motor2.setSpeed(velocidade);
      motor2.run(FORWARD);          
      motor3.setSpeed(velocidade);
      motor3.run(FORWARD);        

      motor1.setSpeed(velocidade); 
      motor1.run(BACKWARD);        
      motor4.setSpeed(velocidade); 
      motor4.run(BACKWARD);
  }
}

void re(int esq,int dir){
      motor1.setSpeed(esq);
      motor1.run(BACKWARD);        
      motor2.setSpeed(dir);
      motor2.run(BACKWARD);        
      motor3.setSpeed(dir);
      motor3.run(BACKWARD);       
      motor4.setSpeed(esq);
      motor4.run(BACKWARD);
  
}

void parar(){
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
  // put your main code here, to run repeatedly:
  
    distanciae=sensore.distance(); //D_E = S_E (cm)
    distanciac=sensorc.distance(); //D_C = S_C (cm)
    distanciad=sensord.distance(); //D_D = S_D (cm)
    
    Serial.println(distanciae);
    Serial.println(distanciac);
    Serial.println(distanciad);
    Serial.println(".........");
    delay(500);

    /*while(distanciac != NULL){
    
    //FRENTE RAPIDO
    if(distanciae > 40 && distanciac > 60 && distanciad > 40)
    frente(70);

    
    //FRENTE LENTO
    else if(distanciae > 40 && distanciac <= 60 && distanciac > 30 && distanciad > 40)
    frente(55);

    
    //FRENTE VIRANDO ESQUERDA
    else if(distanciae > 40 && distanciac > 30 && distanciad <=40 && distanciad > 20)
    frente_virando(30,60);

    
    //FRENTE VIRANDO DIREITA
    else if(distanciae <= 40 && distanciae > 20 && distanciac > 30 && distanciad > 40)
    frente_virando(60,30);

    
    //VIRAR ESQUERDA NO EIXO
    //sentido = 0 (horario), sentido = 1 (antihorario)
    else if(distanciae > 20 && distanciac >=15 && distanciad <= 20)
    virar_eixo(1,65);

    
    //VIRAR DIREITA NO EIXO
    //sentido = 0 (horario), sentido = 1 (antihorario)
    else if(distanciae <= 20 && distanciac >=15 && distanciad > 20)
    virar_eixo(0,65);

    
    //DAR RÉ RETO
    else if(distanciac < 15 && distanciae > 20 && distanciad > 20)
    re(55,55);

    
    //DAR RÉ VIRANDO ESQUERDA
    else if(distanciac < 15 && distanciad <= 20)
    re(55,30);

    
    //DAR RÉ VIRANDO DIREITA
    else if (distanciac < 15 && distanciae <= 20)
    re(30,55);
    }*/
}
