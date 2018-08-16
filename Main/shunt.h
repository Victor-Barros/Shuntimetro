double shunt_current=0;
float shuntvoltage,busvoltage,loadvoltage;

void read_shunt() {
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  shunt_current = ina219.getCurrent_mA();
  //if (shunt_current>204.8) shunt_current-=204.8;
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  if (debug) {
    Serial.print("Shunt Current(mA)=");
    Serial.println(shunt_current);
  }
}


