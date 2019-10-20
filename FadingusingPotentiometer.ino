int in=0;
int led=9;
void setup(){
pinMode(led,OUTPUT);
pinMOde(in,INPUT);
serial.begin(9600);
}
void loop(){
int sensorValue=analogRead(in);
int convertedvalue=map(sensorvalue,0,1023,0,255);
analogWrite(led,convertedvalue);
delay(1000);
serial.println(sensorvalue);
serial.println(convertedValue);
}
}
