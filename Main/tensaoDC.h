double dc_voltage=0;
boolean dc_millis=0;

void read_DC() { 
  adc2 = ads1115.readADC_SingleEnded(2);
  dc_voltage = adc2*0.1875;
  
  Serial.print("DC Voltage"); 
  if (dc_voltage > 500) { //Acima de 500mV altera a escala
    Serial.print("(V) = ");
    dc_millis=0;
    dc_voltage=dc_voltage/1000; 
  } else {
    Serial.print("(mV) = ");
    dc_millis=1;
  }
  Serial.println(dc_voltage);
}
