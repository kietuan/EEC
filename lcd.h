#ifndef LCD
#define LCD

#include <LiquidCrystal.h>

// initialize the library by providing the nuber of pins to it

#define lcd_rs 10
#define lcd_e 9
#define lcd_d4 8
#define lcd_d5 7
#define lcd_d6 6
#define lcd_d7 5


extern LiquidCrystal lcd;
/*(lcd_rs,lcd_e,lcd_d4,lcd_d5,lcd_d6,lcd_d7);
lcd.begin(16,2); //dimension
lcd.setCursor(0,0);
*//*
void setup() 
{

   // set cursor position to start of first line on the LCD
   
   //text to print
   lcd.print("    COUNTER this is the setup() call");
   delay(100);
   lcd.clear();
   int a=0;
   lcd.setCursor(0,1);
   lcd.print("  ");
   //lcd.print(a);
   lcd.leftToRight();
   //lcd.scrollDisplayLeft();
   //lcd.autoscroll();
   while(a<=100)
   {
     a=a+1;
     delay(50);
     lcd.setCursor(3,1);
      
     lcd.blink();
     //lcd.print("   ");
     lcd.print(a);
    
   }
   //lcd.clear();
   lcd.home();
   lcd.print("get out the setup()");
   delay(1000);
}
void loop()
{
      lcd.clear();
}
*/


#endif