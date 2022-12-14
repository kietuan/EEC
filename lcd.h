#ifndef LCD
#define LCD

#include <LiquidCrystal.h>
#include "keyboard.h"
#include "queue.h"

// initialize the library by providing the nuber of pins to it

#define lcd_rs 10
#define lcd_e 9
#define lcd_d4 8
#define lcd_d5 7
#define lcd_d6 6
#define lcd_d7 5


extern LiquidCrystal lcd;
extern uint8_t numOfChars;
extern queue<char> LCDqueue; //những chữ được đọc từ keyboard và đẩy lên màn hình để hiển thị

void readFromKeyboard();
void transmitData(queue<char> &);



#endif