#include <SoftwareSerial.h>
SoftwareSerial cell(2,3);

void readfn()
   {
if (cell.available()) {
while (cell.available()) {
Serial.write(cell.read());
      }
       }
   }

void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);
cell.begin(9600);
cell.println("AT");
delay(1000);
readfn();
  //New SMS alert
cell.println("AT+CNMI=1,2,0,0,0");  
 }


void loop() {
if(cell.available())
 {
  String message =cell.readString();
Serial.println(message);
if(message.indexOf("SWITCH ON")>0)
  {
digitalWrite(13,HIGH);
  }
else if(message.indexOf("SWITCH OFF")>0)
  {
digitalWrite(13,LOW);
  }
else
  {
Serial.println ("Nothing to do...");
  }
}
}
