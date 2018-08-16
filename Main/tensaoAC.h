float ac_voltage=0;

unsigned long read_peak() {
  int temp,j;
  unsigned long x=0;
  for( j=0;j<100;j++){
    temp=analogRead(A0);
    if(temp>x) x=temp;
    delayMicroseconds(50);
  }
  return x;
}

float read_using_sine_wave() {
  return((map(read_peak(), 0, 1023, 0, 1000))-500)*0.707*2;
}

void read_AC() {
  ac_voltage=read_using_sine_wave();
  if(ac_voltage<0) ac_voltage=0; 
  if (debug) {
    Serial.print("AC Voltage(V)="); 
    Serial.println(ac_voltage);
  }
}
