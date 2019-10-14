#include<SoftwareSerial.h>
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
