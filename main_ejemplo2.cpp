#include <Arduino.h>

#define touch_pin_numer T0
const int LED_PIN = 15;
const int VALUE_THRESHOLD = 79;
int touch_sensor_value=0;
int contador = 0;
int set = 0;

void pulsador(){
  //touch_pad_intr_disable( );
  Serial.println("Interrupcion pulsador");
  contador = 1;   
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("LowPower.IO - Pulsador de madera");
  touchAttachInterrupt(touch_pin_numer, pulsador, 78);
  //touch_pad_intr_enable( );
  pinMode (LED_PIN, OUTPUT);
  contador = 0;
}

void loop() {
  //Lectura GPIO Touch. No todos los GPIO pueden ser de tipo Touch.
  Serial.println("Lectura pin touch");
  touch_sensor_value = touchRead(touch_pin_numer); 
  Serial.print("Touch0 value is = ");
  Serial.println( touch_sensor_value);  

  if (contador == 1){
    set++;
    contador = 0;
  }

  if (set == 1){
    for (int i = 0;i<16;i++){
      digitalWrite(LED_PIN, HIGH);
      delay(i);
      digitalWrite(LED_PIN, LOW);
      delay(16-i);
    }
    digitalWrite(LED_PIN, HIGH);
  }
  else if (set == 2){
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);

  }
  else if (set >= 3 ){
    digitalWrite(LED_PIN, LOW);
    set = 0;
  } 
  
  //touch_pad_intr_enable( );
  delay(1000);
}
