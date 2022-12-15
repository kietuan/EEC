#include "keyboard.h"


ps2keyboard keyboard; //định nghĩa



void ps2keyboard::push(uint8_t scancode) //mỗi lần nhấn là phải đẩy lên màn hình, Nhận scancode, xuất ra mã ascii
{
    char character = 0;
    static char prevChar = 0;

    switch (scancode)
    {
        case 0x5a: character = 0x0d; break; //Enter //bắt đầu xả ra, nhưng không thể làm bằng interupt được
            
        case 0x66: character = 0x08; break; 

        case 0x45:
            character = '0'; break;
        case 0x16:
            character = '1'; break;
        case 0x1e:
            character = '2'; break;
        case 0x26:
            character = '3'; break;
        case 0x25:
            character = '4'; break;
        case 0x02e:
            character = '5'; break;
        case 0x36:
            character = '6'; break;
        case 0x3d:
            character = '7'; break;
        case 0x3e:
            character = '8';  break;
        case 0x46:
            character = '9'; break;
        
        case 0x29:
            character = ' '; break;
        
        case 0x1c:
            character = 'a'; break;
        case 0x32:
            character = 'b'; break;
        case 0x21:
            character = 'c'; break;
        case 0x23:
            character = 'd'; break;
        case 0x24:
            character = 'e'; break;
        case 0x2b:
            character = 'f'; break;
        case 0x34:
            character = 'g'; break;
        case 0x33:
            character = 'h'; break;
        case 0x43:
            character = 'i'; break;
        case 0x3b:
            character = 'j'; break;
        case 0x42:
            character = 'k'; break;
        case 0x4b:
            character = 'l'; break;
        case 0x31:
            character = 'n'; break;
        case 0x3a:
            character = 'm'; break;
        case 0x44:
            character = 'o'; break;
        case 0x4d:
            character = 'p'; break;
        case 0x15:
            character = 'q'; break;
        case 0x2d:
            character = 'r'; break;
        case 0x1b:
            character = 's'; break;
        case 0x2c:
            character = 't'; break;
        case 0x3c:
            character = 'u'; break;
        case 0x2a:
            character = 'v'; break;
        case 0x1d:
            character = 'w'; break;
        case 0x22:
            character = 'x'; break;
        case 0x35:
            character = 'y'; break;
        case 0x1a:
            character = 'z'; break;
    }


    if (character) //bắt đầu viết lên
    {
        if (!(character == ' ' && prevChar == ' '))
            keyboard.buffer.push(character); //vô buffer
        //Serial.println(character);
        prevChar = character;
    }
}


void ps2interrupt()
{
    static uint8_t bitcount = 0; //số bit đã được đọc, tức là hiện tại đang có trong rawvalue
    static uint8_t scancode = 0;
    static uint8_t prevScancode = 0;
    static int16_t rawvalue = 0;
    static unsigned long prevTime = 0;

    unsigned long currentTime = millis();;
    uint8_t bit = digitalRead(data_pin); //giá trị bit đã đọc được để đưa vào

    if (currentTime - prevTime > 250) //hết thời gian cho 1 chu kỳ, ở đây có thể xuất hiện bug, read https://www.networktechinc.com/ps2-prots.html https://www.sra.uni-hannover.de/Lehre/WS21/L_BST/doc/ps2.html
    {
        scancode = 0;
        bitcount = 0;
        rawvalue = 0;
    }

    prevTime = currentTime;
    rawvalue |= (bit << bitcount);
    
    bitcount++;
    if (bitcount == 11) //hết 1 gói bits
    {   
        scancode = (rawvalue >> 1) & 0x00ff; //chuyển được về thứ cần có

        if (prevScancode != 0xf0) //bắt đầu push vào cái queue, những tín hiệu chưa được xử lý; loại bỏ tín hiệu break và 0xf0
        {
            keyboard.push(scancode);
            //Serial.println(scancode, HEX);
        }
        prevScancode = scancode;
        

        rawvalue = 0;
        scancode = 0;
        bitcount = 0;
    }       
}

void ps2keyboard::init()
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

char ps2keyboard::read()
{
    char temp = this->buffer.front();
    this->buffer.pop();

    return temp;
}
