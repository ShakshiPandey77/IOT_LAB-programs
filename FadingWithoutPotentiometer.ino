int green=9;
void setup(){
pinMode(green,OUTPUT);
}
void loop(){
for(int i=0;i<255;i+=10)
analogWrite(9,i);
delay(30);
}
for(int i=255;i>0;i-=10){
analogWrite(9,i);
delay(30);
}
}
