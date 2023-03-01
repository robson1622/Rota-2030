#include <Thermistor.h>

//Chaves 
#define ON 0
#define OFF 1

//Pinagem nos polos positivos das celulas
#define BAT1 A0 
#define BAT2 A1
#define BAT3 A2

//Sensor de corrente
#define CORRENT A7

// constante 5/1023
#define CTE 0.0048876

// numeros de amostra para efetuar a média
int media = 100;

//pinos de controle digital
int contBat1 = 2;
int contBat2 = 3;
int contBat3 = 4;
int contGeral = 5;

//Pinagem dos sensores de temperatura
Thermistor th1(4);
Thermistor th2(5);
Thermistor th3(6);
Thermistor th4(3);

class Hardware{   

  private:
    float tensao[3] = {0,0,0};
    float temp[4] = {0,0,0,0};
    bool chaves[4] = {0,0,0,0};
    float corrente = 0;
    
  
    void atualizarTemperatura(void){
      temp[0] = th1.getTemp();
      temp[1] = th2.getTemp();
      temp[2] = th3.getTemp();
      temp[3] = th4.getTemp();
    }

    void atualizarTensao(void){

      float b1 = 0, b2 = 0 , b3 = 0;
      for (int  i = 0 ; i < media ; i++){
        	b1 += analogRead(BAT1);
          b2 += analogRead(BAT2);
          b3 += analogRead(BAT3);
      }
      //As constantes foram calculadas com base nos divisores de tensão
      //e ajustadas manualmente para a variação de cada resistor
      tensao[2] = b3*CTE/media;
      tensao[1] = (1.97565*CTE*b2/media) - tensao[2];     
      tensao[0] = (29.598*CTE*b1/media) - tensao[2] - tensao[1];   
    }
    
    void atualizarCorrente(void){
      float adc = 0.0;
      for (int i = 0 ; i < media ; i++){
        adc +=  analogRead(CORRENT);
      }
      corrente = ((adc*CTE/media)-2.5)/0.185;
    }

    void atualizarControles(void){
      digitalWrite(contBat1,controles[0]);
      digitalWrite(contBat2,controles[1]);
      digitalWrite(contBat3,controles[2]);
      digitalWrite(contGeral,controles[3]);
    }

  public:

    bool controles[4] = {0,0,0,0};
  
    Hardware():corrente(0){
      pinMode(contBat1,OUTPUT);
      pinMode(contBat2,OUTPUT);
      pinMode(contBat3,OUTPUT);
      pinMode(contGeral,OUTPUT);
    }
    float getVoltage(int i){   
      return tensao[i];
    }    
    float getTemperatura(int i){    
      return temp[i];
    }
    float getCorrente(void){
      return corrente;
    }  
    void atualizar(void){
      digitalWrite(contBat1,OFF);
      digitalWrite(contBat2,OFF);
      digitalWrite(contBat3,OFF);
      digitalWrite(contGeral,OFF);    

      atualizarTemperatura();
      atualizarTensao();
      atualizarCorrente();
      atualizarControles();

    }
};
