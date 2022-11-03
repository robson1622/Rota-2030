
#include "Cel.hpp"
#include "KeyPannel.hpp"

/*
INSTRUCOES DE PINAGENS:
BATTERY 01 A0
BATTERY 02 A1
BATTERY 03 A2

TEMP SENSOR 01 A3
TEMP SENSOR 02 A4
TEMP SENSOR 03 A5
TEMP SENSOR 04 A6

RELAY DE CARGA/DESCARGA D2

RESIST BATRETY 01 D3
RESIST BATTERY 02 D4
RESIST BATTERY 02 D5

LIMITE DE CORRENTE 0 D6
LIMITE DE CORRENTE 5 D7
LIMITE DE CORRENTE 10 D8
*/
Cel(int pinPo,int pinTemp)
Cel Bat01(0,3);
Cel Bat02(1,4);
Cel Bat03(2,5);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
