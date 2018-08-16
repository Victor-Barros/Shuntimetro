#include <math.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_INA219.h> 
Adafruit_INA219 ina219;
Adafruit_ADS1115 ads1115;
int16_t adc0;
int16_t adc1;
int16_t adc2;
boolean debug;
#include "tensaoAC.h"
#include "corrente.h"
#include "freq.h"
#include "shunt.h"
#include "tensaoDC.h"
String mensagem_bluetooth;

void contPulsos()
{
  pulsos++;
}

void leituras() {
  read_freq();
  read_current();
  read_shunt();
  read_AC();
  read_DC();
  delay(50);
}

void enviar_bluetooth() {
  mensagem_bluetooth="";
  mensagem_bluetooth+="*a"+String(freq)+"*";
  mensagem_bluetooth+="*b"+String(current)+"**B"+String(current)+",*";
  mensagem_bluetooth+="*c"+String(shunt_current)+"**C"+String(shunt_current)+",*";
  mensagem_bluetooth+="*d"+String(ac_voltage)+"**D"+String(ac_voltage)+",*";
  mensagem_bluetooth+="*e"+String(dc_voltage)+"**E"+String(dc_voltage)+",*";
  if (dc_millis) mensagem_bluetooth+="*fmV*";
  else mensagem_bluetooth+="*fV*";
  Serial.println(mensagem_bluetooth);
}

void setup() {
  pinMode(9, INPUT_PULLUP);
  if (digitalRead(9) == 1) { 
    debug=1;
    Serial.begin(9600);      //Modo de debug
  } else {   
    debug=0;                
    Serial.begin(115200);    //Modo Bluetooth
  }
  
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),contPulsos, FALLING);
  ads1115.begin();
  ina219.begin();
  ina219.setCalibration_16V_400mA(); 
}

void loop() {
  leituras();
  if (!debug) enviar_bluetooth();
  else delay(500);
}
