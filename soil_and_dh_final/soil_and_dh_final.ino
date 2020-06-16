#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int output_value ;
int output_value1;
int sensor_pin=A0;
#define relay 9

void setup(){
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  pinMode(relay, OUTPUT);
  digitalWrite(relay,HIGH);
  delay(2000);
  
}

void loop()
{


  output_value= analogRead(sensor_pin);

  output_value1 = map(output_value,0,1023,0,100);

  Serial.print("Mositure : ");

  Serial.println(output_value1);

  Serial.println("%");

  
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(2000);

  if(output_value < 50)
  {
    digitalWrite(relay, HIGH);
  }

  else// if(output_value > 50)
  {
    digitalWrite(relay, LOW);
  }


  
}
