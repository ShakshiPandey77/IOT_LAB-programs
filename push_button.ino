int ButtonRead=0;
void setup() {
 pinMode(2,INPUT);
 pinMode(13,OUTPUT);

}

void loop() {
  ButtonRead =digitalRead(2);
  if (ButtonRead==HIGH)
  {
    digitalWrite(13,HIGH);}
 else
    {digitalWrite(13,LOW);
  }
  

}
