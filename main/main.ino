#include "main.h"


void setup() 
{
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    Serial.println("Hello Computer");
    a();b();_c();

    keyboard.init(); //khởi tạo
    pinMode(output_pin, OUTPUT);
    digitalWrite(output_pin, LOW);
    lcd.begin(16,2); //dimension
    lcd.setCursor(0,0);
    lcd.cursor();
    lcd.blink();
}

void loop() 
{
    if(keyboard.available())
    {
        if (keyboard.buffer.back() == 0x0d) //gặp enter
        {
            keyboard.transmitData();
        }
    }
}
