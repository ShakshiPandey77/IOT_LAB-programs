#include <SoftwareSerial.h>
SoftwareSerial cell(2,3);
void setup() {
cell.begin(9600);
delay(500);
Serial.begin(9600);
}
void loop() {
int val=analogRead(A0);
Serial.println(val);
delay(1000);
if (val<50)
  {
Serial.println("CALLING..........");
cell.println("ATD+919409492522;");
delay(10000);
cell.println("ATH");  // Attention Hook Control
   }
}
