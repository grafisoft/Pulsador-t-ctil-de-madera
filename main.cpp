#include <Arduino.h>

#define touch_pin_numer T0
const int LED_PIN = 15;
const int VALUE_THRESHOLD = 79;
int touch_sensor_value=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("LowPower.IO - Pulsador de madera");  
  pinMode (LED_PIN, OUTPUT);  
}

void loop() {
  //Lectura GPIO Touch. No todos los GPIO pueden ser de tipo Touch.
  Serial.println("Lectura pin touch");
  touch_sensor_value = touchRead(touch_pin_numer); 
  Serial.print("Touch0 value is = ");
  Serial.println( touch_sensor_value);  

  //Hacemos algo al pulsar.  
  if(touch_sensor_value < VALUE_THRESHOLD)
  {     
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  } 
 
  delay(1000);
}