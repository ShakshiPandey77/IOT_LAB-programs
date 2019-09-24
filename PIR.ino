int p=13;  
int pir=2;
void setup()
{
  pinMode(p,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int v=digitalRead(pir);
  digitalWrite(p,v);
  Serial.println(v);
}
/*swap ground and vcc if it does not work.*/

