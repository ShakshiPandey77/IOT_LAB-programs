void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int rv=analogRead(A0);
  float mv=(rv/1024.0)*5000;
  float c=mv/10;
  Serial.println("celcius:");
  Serial.println(c);
  Serial.println("fahrenheit :");
  Serial.println(c*9/5+32);
  delay(1000); 
}

