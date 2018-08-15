float current=0;
int offset = 2435;

void read_current(){
  adc0 = ads1115.readADC_SingleEnded(0);
  current = ((adc0*0.1875)-offset)/66;
  Serial.print("AC/DC Current(A)=");
  Serial.println(adc0);
}
