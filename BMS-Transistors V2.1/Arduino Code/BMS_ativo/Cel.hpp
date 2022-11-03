
//pinP e pinN são os contatos da bateria, pinT é a entrada de dados do sensor de temperatura
#include "TempSensor.hpp"

//pinos das tensoes das baterias, será necessário um calculo para ter a tensão de cada uma
int B1 3;
int B2 4;
int B3 5;

float REFB1 4.1336;
float REFB2 4.2;

class Cel{
  
  private:
  
  int pinP;
  float voltage;
  float temp;
  TempSensor sensor;
  float tensaoRef;
  
  public:
  
  Cel(int pinPo,int pinTemp,int numCel):sensor(pinTemp){
    pinP = pinPo;
    if(numCel != 1)
      tensaoRef = REFB2;
    else 
      tensaoRef = REFB1;
  }
  //deve-se associar um resistor de 20k em serie com o NTC e ligar o pinT no meio dessa serie.
  float getTemp(){
    return  sensor.getTemp();
  }
  
  float getVoltage(){
    voltage = analogRead(pinP)*tensaoRef/1023);
    return voltage;
  }
};
