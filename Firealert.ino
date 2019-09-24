#include<SoftwareSerial.h>
int sensorPin=A0;
int sensorValue=0;
int led=9;
int buzzer=12;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.println("welcome to tech plane sensor");
  sensorValue=analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue<100)
  {
    Serial.println("fire detected");
    Serial.println("led on");
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(1000);
  }
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
  delay(sensorValue);
}
