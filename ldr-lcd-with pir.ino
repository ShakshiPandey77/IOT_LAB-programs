#include<LiquidCrystal.h>

int LDR = 1;     //analog pin to which LDR is connected, here we set it to 0 so it means A0
int LDRValue = 0;      //that’s a variable to store LDR values
int light_sensitivity = 100;    //This is the approx value of light surrounding your LDR

//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  
boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 8;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel

void setup()
  {
    lcd.begin(16, 2);               // start the library
    lcd.setCursor(0,0);             // set the LCD cursor   position 
    pinMode(11, OUTPUT);     

    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(pirPin, LOW);

    lcd.print("calibrating sensor ");//give the sensor some time to calibrate
    for(int i = 0; i<calibrationTime; i++){
        lcd.print(".");
        delay(1000);
     }
     lcd.print(" done");
     lcd.print("SENSOR ACTIVE");
     delay(50);
  }
 
void loop()
  {
    LDRValue = analogRead(LDR);      //reads the ldr’s value through LDR 
    //  Serial.println(LDRValue);       //prints the LDR values to serial monitor
     
      if(digitalRead(pirPin) == HIGH && LDRValue < light_sensitivity){
        digitalWrite(ledPin, HIGH);   
        if(lockLow){  
            //makes sure we wait for a transition to LOW before any further output is made:
            lockLow = false;            
            /*Serial.println("---");
            Serial.print("motion detected at ");*/
            lcd.print(millis()/1000);
            lcd.print(" sec"); 
            delay(50);
         }         
        takeLowTime = true;
      }
       
      if(digitalRead(pirPin) == LOW ||  LDRValue >= light_sensitivity){       
          digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
          if(takeLowTime){
            lowIn = millis();          //save the time of the transition from high to LOW
            takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
      if(!lockLow&&millis() - lowIn> pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
        lockLow = true;                        
        //Serial.print("motion ended at ");      //output
        lcd.print((millis() - pause)/1000);
        lcd.println(" sec");
        delay(50);
    }
      delay(100);
  }
}
