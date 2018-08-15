double dc_voltage=0;
boolean dc_millis=0;

void read_DC() { 
  adc2 = ads1115.readADC_SingleEnded(2);
  dc_voltage = adc2*0.1875;

  if (dc_voltage > 500) { //Acima de 500mV altera a escala
      dc_millis=0;
      dc_voltage=dc_voltage/1000; 
  } else {
    dc_millis=1;
  }
  
  if (debug) {
    Serial.print("DC Voltage"); 
    if (dc_millis) Serial.print("(V) = ");
    else Serial.print("(mV) = ");
    Serial.println(dc_voltage);
  }
}
