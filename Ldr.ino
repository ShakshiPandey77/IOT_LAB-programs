
int ledPin=13;
int analogPin=A0;
int threshold=500;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(analogPin,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  int sensedValue=analogRead(analogPin);
  Serial.print("Read Value");
  Serial.println(sensedValue);
 
  if(sensedValue<threshold)
  {
    digitalWrite(ledPin,HIGH);
    delay(1000);
    
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }


}
