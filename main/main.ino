#include "main.h"


void setup() 
{
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
