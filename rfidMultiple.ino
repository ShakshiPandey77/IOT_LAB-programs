#include<SoftwareSerial.h>        //with led
SoftwareSerial myserial(9,10);
#define led 12
char tag[]="53002913C4AD";
char input[12];
int count=0;
boolean flag=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myserial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(myserial.available()){
  count=0;
  while(myserial.available()&& count<12){
    input[count]=myserial.read();
    Serial.write(input[count]);
    count++;
    delay(5);
    }
    if(count==12){
      count=0;
      flag=1;
      while(count<12&&flag!=0){
        if(input[count]==tag[count]){
          flag=1;
          }
          else{
            flag=0;
            }
            count++;
        }
      }
      if(flag==1){
        Serial.println("accesss allowed");
        digitalWrite(led,HIGH);
        delay(2000);
        digitalWrite(led,LOW);
        }
        else{
          Serial.print("access denied");
          digitalWrite(led,LOW);
          delay(2000);
          }
          for(count=0;count<12;count++){
            input[count]='F';
            }
            count=0;
  }
}








/* #include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int read_count=0,tag_count=0;
int j=0,k=0; // Variabvles to iterate in for loops
char data_temp, RFID_data[12], data_store[10][12];
boolean disp_control;

void setup()
{
mySerial.begin(9600);
Serial.begin(9600);
}

void loop()
{
RecieveData();
StoreData();
PrintData();
}

void RecieveData()
{
if(mySerial.available()>0)
{
data_temp=mySerial.read();
RFID_data[read_count]=data_temp;
read_count++;
}
}

void StoreData()
{

if(read_count==12)
{
disp_control=true;  
for(k=tag_count;k<=tag_count;k++)
{
for(j=0;j<12;j++)
{
data_store[k][j]=RFID_data[j];
}
}
read_count=0;
tag_count++;
}
}

void PrintData()
{
if(disp_control==true)
{
  for(k=0;k<=tag_count;k++)
{
    for(j=0;j<12;j++)
  {
    Serial.write(data_store[k][j]);
  }
  Serial.println();
}
disp_control=false;
} 
}
*/
