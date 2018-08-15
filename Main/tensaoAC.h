float ac_voltage=0;

unsigned long read_peak(int adc_pin) {
  int temp,j;
  unsigned long x=0;
  for( j=0;j<510;j++){
    adc1 = ads1115.readADC_SingleEnded(adc_pin);
    if(temp>x) x=temp;
    delayMicroseconds(50);
  }
  return x;
}

float read_using_sine_wave(int adc_pin) {
  return((map(read_peak(adc_pin), 0, 65535, 0, 1000))-500)*0.707*2;
}

void read_AC() {
  ac_voltage=read_using_sine_wave(1);
  if(ac_voltage<0) ac_voltage=0; 
  if (debug) {
    Serial.print("AC Voltage(V)="); 
    Serial.println(ac_voltage);
  }
}
