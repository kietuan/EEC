#include "keyboard.h"

LiquidCrystal lcd(lcd_rs,lcd_e,lcd_d4,lcd_d5,lcd_d6,lcd_d7);
lcd.begin(16,2); //dimension
lcd.setCursor(0,0);

ps2keyboard keyboard;


 
void ps2keyboard::push(uint8_t scancode) //mỗi lần nhấn là phải đẩy lên màn hình, Nhận scancode, xuất ra mã ascii
{
    char character = 0;
    switch (scancode)
    {
        case 0x1c: //Enter
            return;
        case 0x0e: //backspace
            keyboard.buffer.pop_back();
            return;

        case 0x0b:
            character = '0'; break;
        case 0x02:
            character = '1'; break;
        case 0x03:
            character = '2'; break;
        case 0x04:
            character = '3'; break;
        case 0x05:
            character = '4'; break;
        case 0x06:
            character = '5'; break;
        case 0x07:
            character = '6'; break;
        case 0x08:
            character = '7'; break;
        case 0x09:
            character = '8';  break;
        case 0x0a:
            character = '9'; break;
        
        case 0x39:
            character = ' '; break;
        
        case 0x1e:
            character = 'a'; break;
        case 0x30:
            character = 'b'; break;
        case 0x2e:
            character = 'c'; break;
        case 0x20:
            character = 'd'; break;
        case 0x12:
            character = 'e'; break;
        case 0x21:
            character = 'f'; break;
        case 0x22:
            character = 'g'; break;
        case 0x23:
            character = 'h'; break;
        case 0x17:
            character = 'i'; break;
        case 0x24:
            character = 'j'; break;
        case 0x25:
            character = 'k'; break;
        case 0x26:
            character = 'l'; break;
        case 0x32:
            character = 'm'; break;
        case 0x18:
            character = 'o'; break;
        case 0x19:
            character = 'p'; break;
        case 0x10:
            character = 'q'; break;
        case 0x13:
            character = 'r'; break;
        case 0x1f:
            character = 's'; break;
        case 0x14:
            character = 't'; break;
        case 0x16:
            character = 'u'; break;
        case 0x2f:
            character = 'v'; break;
        case 0x11:
            character = 'w'; break;
        case 0x2d:
            character = 'x'; break;
        case 0x15:
            character = 'y'; break;
        case 0x2c:
            character = 'z'; break;
    }

    if (character) //bắt đầu viết lên
    {
        keyboard.buffer.push(character);

        //bắt đầu ghi ra màn hình

    }
}


ps2keyboard::ps2keyboard() : buffer{}
{
    pinMode(clk_pin, INPUT_PULLUP); //Khởi tạo ngay từ lúc một biến được tạo ra
    pinMode(data_pin, INPUT_PULLUP);
    pinMode(output_pin, OUTPUT);
    digitalWrite(output_pin, LOW);
    attachInterrupt(digitalPinToInterrupt(clk_pin), ps2interrupt, FALLING);
}

bool ps2keyboard::available() const
{
    return !(buffer.isEmpty());
}


void ps2interrupt()
{
    static uint8_t bitcount = 0; //số bit đã được đọc, tức là hiện tại đang có trong rawvalue
    static uint8_t incoming = 0;
    static uint8_t scancode = 0; 
    static int16_t rawvalue = 0;

    static unsigned long prevTime = 0;
    unsigned long currentTime;
    uint8_t bit;

    bit = digitalRead(data_pin); //giá trị bit đã đọc được để đưa vào
    currentTime = micros();
    if (currentTime - prevTime > 500) //hết thời gian cho 1 chu kỳ, ở đây có thể xuất hiện bug, read https://www.networktechinc.com/ps2-prots.html https://www.sra.uni-hannover.de/Lehre/WS21/L_BST/doc/ps2.html
    {
        scancode = 0;
        bitcount = 0;
        rawvalue = 0;
    }

    rawvalue |= (bit << bitcount);
    bitcount++;
    if (bitcount == 11) //hết 1 gói bits
    {
        rawvalue &= 0b0000001111111100;
        scancode = rawvalue >> 2;
        //chuyển scancode này thành ascii rồi lưu vào buffer. nếu = 0 thì thôi đừng lưu, như vậy thì chỉ có 1 lần nhất là được ghi, lần nhả không ghi
        keyboard.push(scancode);

        rawvalue = 0;
        scancode = 0;
        bitcount = 0;
    }    
}

