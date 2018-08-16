double dc_voltage=0;
double dc_voltage_mv=0;

void read_DC() { 
  adc2 = ads1115.readADC_SingleEnded(2);
  dc_voltage_mv = (adc2*0.1875*10.95);
  dc_voltage = dc_voltage_mv/1000;
  
  if (debug) {
    Serial.print("DC Voltage(V) = ");
    Serial.println(dc_voltage);
    Serial.print("DC Voltage(mV) = ");
    Serial.println(dc_voltage_mv);
  }
}
