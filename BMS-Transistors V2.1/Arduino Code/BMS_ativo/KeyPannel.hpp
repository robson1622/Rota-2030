#include "Relay.hpp"

class KeyPannel{
  private:
  
  bool disB1On;
  bool disB2On;
  bool disB3On;

  bool chargeOn;
  
  int disB1;
  int disB2;
  int disB3;

  int charge;

  public:
  KeyPannel(int dischargeB1, int dischargeB2, int dischargeB3, int chargePin,int relayPin): charge(relayPin){
    disB1 = dischargeB1;
    disB2 = dischargeB2;
    disB3 = dischargeB3;

    charge = chargePin;

    pinMode(disB1,OUTPUT);
    pinMode(disB2,OUTPUT);
    pinMode(disB3,OUTPUT);
    pinMode(chargePin,OUTPUT);
    
    digitalWrite(disB1,LOW);
    digitalWrite(disB2,LOW);
    digitalWrite(disB3,LOW);
    digitalWrite(chargePin,LOW);
  }
  void turnOnDischargeB1(){
    digitalWrite(disB1,HIGH);
    disB1On = true;
  }
  void turnOffDischargeB1(){
    digitalWrite(disB1,LOW);
    disB1On = false;
  }
  void turnOnDischargeB2(){
    digitalWrite(disB2,HIGH);
    disB2On = true;
  }
  void turnOffDischargeB2(){
    digitalWrite(disB2,LOW);
    disB2On = false;
  }
  void turnOnDischargeB3(){
    digitalWrite(disB3,HIGH);
    disB3On = true;
  }
  void turnOffDischargeB3(){
    digitalWrite(disB3,LOW);
    disB3On = false;
  }
  bool dischargingB1(){
    return disB1On;
  }
  bool dischargingB2(){
    return disB2On;
  }
  bool dischargingB3(){
    return disB3On;
  }
  void On(){
    charge.turnOn();
  }
  void Off(){
    charger.turnOff();
  }
};
