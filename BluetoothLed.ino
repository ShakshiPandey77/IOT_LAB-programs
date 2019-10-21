#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

#define ledPin 9

String message;

int potValue = 0;

void setup() {

pinMode(ledPin, OUTPUT);

digitalWrite(ledPin, LOW);

Serial.begin(9600);

BTSerial.begin(38400); // HC-05 default speed in AT command more

}

void loop() {

if(BTSerial.available() > 0){

// Checks whether data is comming from the serial port

// Reads the data from the serial port

message = BTSerial.readString();

// Controlling the LED

if(message.indexOf("SWITCH ON")>=0)

{

digitalWrite(ledPin, HIGH); // LED ON

}

else if(message.indexOf("SWITCH OFF")>=0)

{

digitalWrite(ledPin, LOW); // LED OFF

}

else

{

Serial.println("Noting to do");

}

delay(100);

}

delay(10);

}
