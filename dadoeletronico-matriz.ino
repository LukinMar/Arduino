/*Created by Rui Santos
 http://randomnerdtutorials.com/
---------------------------------
 
 Modificado por Rodrigo Costa
 https://eletronicaparatodos.com/
 Em: 14/03/2017
---------------------------------------------------------------------------
 INSTRUCOES PARA INTERFACE DOS PINOS DA MATRIZ COM OS PINOS DO ARDUINO UNO:
---------------------------------------------------------------------------
 DIN se conecta ao pino 12
 CLK se conecta ao pino 11
 CS se conecta ao pino 10 
*/
 
#include "LedControl.h"
#include "binary.h"
 
LedControl lc = LedControl(12,11,10,1);
 
byte zero[] = {
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};
 
byte um[] = {
B00000000,
B00000000,
B00000000,
B00011000,
B00011000,
B00000000,
B00000000,
B00000000};
 
byte dois[] ={
B00000000,
B01100000,
B01100000,
B00000000,
B00000000,
B00000110,
B00000110,
B00000000};
 
byte tres[]={
B11000000,
B11000000,
B00000000,
B00011000,
B00011000,
B00000000,
B00000011,
B00000011};
 
byte quatro[]={
B00000000,
B01100110,
B01100110,
B00000000,
B00000000,
B01100110,
B01100110,
B00000000};
 
byte cinco[]={
B11000011,
B11000011,
B00000000,
B00011000,
B00011000,
B00000000,
B11000011,
B11000011};
 
byte seis[]={
B00000000,
B11011011,
B11011011,
B00000000,
B00000000,
B11011011,
B11011011,
B00000000};
 
const int pinoBotao = 8;
int  leituraBotao;
int resultado = 0;

void setup(){
  
  pinMode(pinoBotao, INPUT_PULLUP);  //Inicializa o push button
   leituraBotao = digitalRead(pinoBotao);
  randomSeed(analogRead(0));
  lc.shutdown(0,false);
 
  // Se o pino de entrada analógica 5 estiver desconectado, leia análogo aleatório
  // o ruído fará com que a chamada para randomSeed () gere
  // diferentes números de sementes cada vez que o programa/sketch é executado. 
  // randomSeed () irá então tornar a função random() aleatória.
  
  // Ajustamos o brilho da matriz de leds para um valor médio
  lc.setIntensity(0,10);
  
  // Limpamos o display
  lc.clearDisplay(0); 
}
 
void loop() {
  //lc.clearDisplay(0);
 resultado = random(1, 7);
  if (leituraBotao == HIGH){
    rolaDado();
  }
  delay(50);
}
 
void rolaDado(){
  //int resultado = 0;
  int tempoDadoRolando = random(10, 15);
  
  for(int i=0; i<tempoDadoRolando; i++){
    // A variável resultado vai assumir um valor entre 1 e 6
    resultado = random(1, 7); 
    mostraResultado(resultado);
    delay(100 + i * 10);
  }
  for(int i=0; i<2; i++){
    mostraResultado(0);
    delay(500);
    mostraResultado(resultado);
    delay(250);
  }
}
 
void mostraResultado(int resultado){
  if(resultado==0){
    lc.setRow(0,0,zero[0]);
    lc.setRow(0,1,zero[1]);
    lc.setRow(0,2,zero[2]);
    lc.setRow(0,3,zero[3]);
    lc.setRow(0,4,zero[4]);
    lc.setRow(0,5,zero[5]);
    lc.setRow(0,6,zero[6]);
    lc.setRow(0,7,zero[7]);
  }
  else if(resultado==1){
    lc.setRow(0,0,um[0]);
    lc.setRow(0,1,um[1]);
    lc.setRow(0,2,um[2]);
    lc.setRow(0,3,um[3]);
    lc.setRow(0,4,um[4]);
    lc.setRow(0,5,um[5]);
    lc.setRow(0,6,um[6]);
    lc.setRow(0,7,um[7]);
  }
  else if(resultado==2){
    lc.setRow(0,0,dois[0]);
    lc.setRow(0,1,dois[1]);
    lc.setRow(0,2,dois[2]);
    lc.setRow(0,3,dois[3]);
    lc.setRow(0,4,dois[4]);
    lc.setRow(0,5,dois[5]);
    lc.setRow(0,6,dois[6]);
    lc.setRow(0,7,dois[7]);
  }
  else if(resultado==3){
    lc.setRow(0,0,tres[0]);
    lc.setRow(0,1,tres[1]);
    lc.setRow(0,2,tres[2]);
    lc.setRow(0,3,tres[3]);
    lc.setRow(0,4,tres[4]);
    lc.setRow(0,5,tres[5]);
    lc.setRow(0,6,tres[6]);
    lc.setRow(0,7,tres[7]);
  }
  else if(resultado==4){
    lc.setRow(0,0,quatro[0]);
    lc.setRow(0,1,quatro[1]);
    lc.setRow(0,2,quatro[2]);
    lc.setRow(0,3,quatro[3]);
    lc.setRow(0,4,quatro[4]);
    lc.setRow(0,5,quatro[5]);
    lc.setRow(0,6,quatro[6]);
    lc.setRow(0,7,quatro[7]);
  }
  else if(resultado==5){
    lc.setRow(0,0,cinco[0]);
    lc.setRow(0,1,cinco[1]);
    lc.setRow(0,2,cinco[2]);
    lc.setRow(0,3,cinco[3]);
    lc.setRow(0,4,cinco[4]);
    lc.setRow(0,5,cinco[5]);
    lc.setRow(0,6,cinco[6]);
    lc.setRow(0,7,cinco[7]);
  }
  else if(resultado==6){
    lc.setRow(0,0,seis[0]);
    lc.setRow(0,1,seis[1]);
    lc.setRow(0,2,seis[2]);
    lc.setRow(0,3,seis[3]);
    lc.setRow(0,4,seis[4]);
    lc.setRow(0,5,seis[5]);
    lc.setRow(0,6,seis[6]);
    lc.setRow(0,7,seis[7]);
  }
}
