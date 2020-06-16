//#include <dht.h>

//#include <SoftwareSerial.h>  //including the software serial UART library which will make the digital pins as TX and RX
//#include <LiquidCrystal.h>
#include "DHT.h"             //including the DHT22 library
#define DHTPIN 8             //Declaring pin 8 of arduino to communicate with DHT22
#define DHTTYPE DHT11        //Defining type of DHT sensor we are using (DHT22 or DHT11)
#define DEBUG true
DHT dht(DHTPIN, DHTTYPE);    //Declaring a variable named dht
//LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
//SoftwareSerial esp8266(2,3); //Connect the TX pin of ESP8266 to pin 2 of Arduino and RX pin of ESP8266 to pin 3 of Arduino.
//SoftwareSerial mySerial(9, 10);

int motor=7;
const int motor2 = 5;
const int motor3= 4;
const int fan=6;
float temp_read,Temp_alert_val,Temp_shut_val;
float sound,db;
float soil,soill,soil2,soill2,soil3,soill3;
int buttonState1=0;
int buttonState2=0;


void setup()
{
  Serial.begin(9600);
    //lcd.begin(16,2); 
  // mySerial.begin(9600); 
  //esp8266.begin(115200); // Set the baud rate of serial communication
 // dht.begin();         //This will initiate receiving data from DHT22

pinMode(motor, OUTPUT);
pinMode(motor2, OUTPUT);
 pinMode(motor3,OUTPUT);
 pinMode(fan,OUTPUT);
//lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print("T: ");
//lcd.setCursor(8,0); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print("C: ");

//lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print("S: ");
//delay(30);
//lcd.setCursor(8,1); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print("G: ");
}

void loop()
{
  
 
  soil=analogRead(1);
  soill=(100-((soil/1023.00)*100));
  Serial.println(soil);
  //lcd.setCursor(10,0); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print( soill);


 if(soill>20)
        {
          digitalWrite(motor,HIGH);
         
          }
          else 
          {
            digitalWrite(motor,LOW);
         
            }            
  
}
