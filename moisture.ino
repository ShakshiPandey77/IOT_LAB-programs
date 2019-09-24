#include<Servo.h>
Servo myservo;
int pos=0;
int sp=A0;
int sv=0;
void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
}
void loop(){
  sv=analogRead(sp);
  Serial.println(sv);
  if(sv>1000)
  {
    for(pos=0;pos<=180;pos+=1)
    {
      myservo.write(pos);
      delay(15);
    }
    for(pos=180;pos>=0;pos-=1)
    {
      myservo.write(pos);
      delay(15);
    }}
    delay(1000);
}

