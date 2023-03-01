#include "Software.hpp"

Software sof;
/*
 *ORIENTAÇÕS DE PINAGEM*
  

  SENSOR TEMP 0 = A0;
  SENSOR TEMP 0 = A1;
  SENSOR TEMP 0 = A2;
  SENSOR TEMP 0 = A3;

  BATTERY 1 = A4;
  BATTERY 2 = A5;
  BATTERY 3 = A6;
  
  CONTROLE RESISTOR B1 = 13;
  CONTROLE RESISTOR B1 2 = 12;
  CONTROLE RESISTOR B1 3 = 11;
  CONTROLE CARREGAMENTO = 10;

  SENSOR DE CORRENTE = A7;
*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sof.rotinaCarga01();
  sof.printInfors();  
  delay(5000); 
}
