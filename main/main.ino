#include "main.h"


void setup() 
{
    //Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    //Serial.println("Getting started");
    //a();b();_c();

    keyboard.init(); //khởi tạo
    pinMode(output_pin, OUTPUT);
    digitalWrite(output_pin, LOW);
    lcd.begin(16,2); //dimension
    lcd.setCursor(0,0);
    lcd.cursor();
    lcd.blink();
    lcd.write("Hello");
    delay(5000);
    lcd.clear();    
}

void loop() 
{
  
  while(keyboard.available())
  {
      readFromKeyboard();
  }
  digitalWrite(output_pin, LOW);
}
