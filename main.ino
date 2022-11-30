#include "keyboard.h"
#include "LiquidCrystal.h"
#include "morseEncoder.h"


void setup() 
{
    keyboard.init(4,3);
}

void loop() 
{
    while(keyboard.available())
    {
        if (keyboard.buffer.back() == _ENTER)
        {
            
            continue;
        }
    }
}
