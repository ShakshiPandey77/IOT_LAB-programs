
int tr=8;
int ec=9;
void setup()
{
  pinMode(tr,OUTPUT);
  pinMode(ec,INPUT);
  Serial.begin(9600);
}
void loop()
{
 digitalWrite(tr, LOW);
delayMicroseconds(2);
digitalWrite(tr, HIGH);
//delayMicroseconds(10);
//digitalWrite(tr, LOW);
  long duration=pulseIn(ec,HIGH);
 double distance=duration*0.034/2;
  Serial.print("\ndistance");
  Serial.print(distance);
}
