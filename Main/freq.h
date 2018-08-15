float freq=0;
volatile unsigned long pulsos = 0;
unsigned long tempo = 0;
unsigned long onelasttime = 0;

void read_freq() {
  tempo = millis();
  if((tempo - onelasttime) >= 1000){
    noInterrupts();
    freq = pulsos*(tempo/1000);
    pulsos = 0;
    onelasttime = tempo;
    interrupts();
  }
  if (debug) {
    Serial.print("Frequency(Hz)=");
    Serial.println(freq);
  }
}

