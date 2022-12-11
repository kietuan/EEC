#ifndef PS2_KEYBOARD
#define PS2_KEYBOARD

#include "Arduino.h"
#include "lcd.h"

#define PS2_KEYMAP_SIZE 38
#define CLK_PERIOD

#define data_pin 4
#define clk_pin 3
#define output_pin 1

class ps2keyboard;
extern ps2keyboard keyboard; //1 biến global dùng để lưu trữ 1 bàn phím hiện tại; forward declare




class ps2keyboard //object xử lý input
{
    friend void ps2interrupt();

    queue<char> buffer{}; //chứa các chữ đã được xử lý
public:
    ps2keyboard();

    //void    init(uint8_t data_pin, uint8_t clk_pin);
    void    push (uint8_t);
    void    clear();
    int     read(); //đọc ký tự tiếp theo chỉ khi gặp trúng được _ENTER
    uint8_t readScanCode() const;
    bool    available() const; //Nếu sẵn có chữ trong buffers để đọc


private:
};

void ps2interrupt();


#endif