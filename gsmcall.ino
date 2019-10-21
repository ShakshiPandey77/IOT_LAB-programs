#include <SoftwareSerial.h>
SoftwareSerial cell(2,3);  // (Rx, Tx) 2,3 to TX,RX of GSM

void setup() {
cell.begin(9600);
delay(500);
Serial.begin(9600);
Serial.println("CALLING..........");
cell.println("ATD+919409492522;");   // ATD – Attention Dial
delay(20000);
}
void loop() {
  
}
