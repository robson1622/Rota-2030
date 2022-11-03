




class TempSensor{
  int pin;

  TempSensor(int pinN){
    pin = pinN;
  }
  float getTemp(void){
    float ResSensor = 22000*(5-analogRead(pinT))/5;
    //B e Rx são fornecidos pelo fabricante, verificar e subistituir
    int B = 1;
    int Rx = 1;
    temp = B*log(ResSensor/Rx);
    return temp;
  }
}
