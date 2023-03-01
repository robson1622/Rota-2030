#include "Hardware.hpp"

//Para usar a bibliotecade comunicação SPI
#include <SPI.h>

//Para usar a biblioteca de comunicação CAN
#include <mcp2515.h>

//PIN CS
#define CS 3

struct can_frame canMsg;
MCP2515 mcp2515(CS);



//Declara e inicializa o dado que esse controlador CAN transmitirá
int bat1 = 0;
int bat2 = 1;
int bat3 = 2;
int tem1 = 3;
int tem2 = 4;
int tem3 = 5;
int tem4 = 6;
int corr = 7;


class Software{
  private:
    Hardware hard;
    int tempo;
    int segundos;


  public:
  
    Software():hard(),tempo(0){

      mcp2515.reset();
      mcp2515.setBitrate (CAN_500KBPS, MCP_8MHZ);
      mcp2515.setNormalMode();
    }
    void transmitirInforBus(void){
      if(segundos < millis()){
        canMsg.can_id  = 0x036;     //CAN id = 0x036
        canMsg.can_dlc = 4;         //CAN data length = 1 (pode ser no máximo 8 bytes)
        canMsg.data[bat1] = hard.getVoltage(0);  //CAN data0 = Dado lido na Serial
        canMsg.data[bat2] = hard.getVoltage(1);      //CAN data1 = 0
        canMsg.data[bat3] = hard.getVoltage(2);      //CAN data2 = 0
        canMsg.data[tem1] = hard.getTemperatura(0);      //CAN data3 = 0
        canMsg.data[tem2] = hard.getTemperatura(1);      //CAN data4 = 0
        canMsg.data[tem3] = hard.getTemperatura(2);      //CAN data5 = 0
        canMsg.data[tem4] = hard.getTemperatura(3);      //CAN data6 = 0
        canMsg.data[corr] = hard.getCorrente();      //CAN data7 = 0
        
        
        mcp2515.sendMessage(&canMsg);
        segundos = millis() + 1000;  
      }
    }
    void rotinaCarga01(void){
      hard.atualizar();
      if(tempo + 100 < millis()){
        tempo = millis ;
        transmitirInforBus();        
      }
    }
    void printInfors(void){
      Serial.println("-----------------------------------------------------------------"); 
      Serial.print("Corrente : ");
      Serial.println(hard.getCorrente());
      Serial.print("Tensoes : B1 (");
      Serial.print(hard.getVoltage(0));
      Serial.print(")   B2 (");
      Serial.print(hard.getVoltage(1));
      Serial.print(")   B3 (");
      Serial.print(hard.getVoltage(2));
      Serial.println(") ");
      Serial.print("Temperatura : TB1 (");
      Serial.print(hard.getTemperatura(0));
      Serial.print(")   TB2 (");
      Serial.print(hard.getTemperatura(1));
      Serial.print(")   TB3 (");
      Serial.print(hard.getTemperatura(2));
      Serial.print(")   TB4 (");
      Serial.print(hard.getTemperatura(3));
      Serial.println(" ) ");
    }
    
};