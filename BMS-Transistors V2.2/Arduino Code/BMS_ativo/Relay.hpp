

class Relay{
  
  private:
  int pin;
  bool state;

  public:
  Relay(int pinR){
    pin = pinR;
    state = false;
    pinMode(pin,OUTPUT);
  }
  void turnOn(){
    digitalWrite(pin,HIGH);
    state = true;
  }
  void turnOff(){
    digitalWrite(pin,LOW);
    state = false;
  }
  bool getState(){
    return state;
  }
};
