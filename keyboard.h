#ifndef PS2_KEYBOARD
#define PS2_KEYBOARD

#include <Arduino.h>


#include <stdint.h>


#include "lcd.h"
#include "morseEncoder.h"
#include "queue.h"


#define PS2_KEYMAP_SIZE 38
#define CLK_PERIOD

#define data_pin 4
#define clk_pin 3

#ifndef output_pin
#define output_pin 1
#endif

class ps2keyboard;
extern ps2keyboard keyboard; //1 biến global dùng để lưu trữ 1 bàn phím hiện tại; forward declare
extern uint8_t numOfChars;



class ps2keyboard //object xử lý input
{
    friend void ps2interrupt();
public:
    queue<char> buffer{}; //chứa các chữ đã được xử lý

    ps2keyboard() : buffer{} {};

    void    init();
    void    push (uint8_t);
    void    clear();
    char     read(); //đọc ký tự tiếp theo chỉ khi gặp trúng được _ENTER
    uint8_t readScanCode() const;
    bool    available() const; //Nếu sẵn có chữ trong buffers để đọc

    void    transmitData();
};

void ps2interrupt();


#endif