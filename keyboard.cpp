#include "keyboard.h"

LiquidCrystal lcd(lcd_rs,lcd_e,lcd_d4,lcd_d5,lcd_d6,lcd_d7); //khởi tạo

ps2keyboard keyboard; //định nghĩa

uint8_t numOfChars = 0; //dùng để theo dõi số ký tự trên màn hình hiện tại
 
void ps2keyboard::push(uint8_t scancode) //mỗi lần nhấn là phải đẩy lên màn hình, Nhận scancode, xuất ra mã ascii
{
    char character = 0;
    static uint8_t prevScancode = 0;

    if (prevScancode != 0xf0)
        switch (scancode)
        {
            case 0x5a: //Enter //bắt đầu xả ra, nhưng không thể làm bằng interupt được
                character = 0x0d; break;
            case 0x66: //backspace
                keyboard.buffer.clear();
                lcd.clear();
                numOfChars = 0;
                return;

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
    
    prevScancode = scancode;

    if (character) //bắt đầu viết lên
    {
        keyboard.buffer.push(character); //vô buffer

        if (character == 0x0d) return;

        //bắt đầu ghi ra màn hình theo thứ tự từ trái qua và trên xuống dưới
        if (numOfChars == 32)
        {
            lcd.clear();
            numOfChars = 0;
        }

        lcd.write(character);
        numOfChars++;
        if (numOfChars == 16) lcd.setCursor(0,1);
        
    }
}

void ps2interrupt()
{
    static uint8_t bitcount = 0; //số bit đã được đọc, tức là hiện tại đang có trong rawvalue
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

    prevTime = currentTime;
    rawvalue |= (bit << bitcount);
    bitcount++;
    Serial.println(bitcount);
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

 void ps2keyboard::transmitData()
{
    if (keyboard.buffer.back() != 0x0d) return;

    detachInterrupt(digitalPinToInterrupt(clk_pin));
    keyboard.buffer.pop_back(); //xóa ở cuối
    while( !keyboard.buffer.isEmpty() )
    {
        char c = keyboard.buffer.front();
        switch(c)
        {
            case 'q': q(); break;
            case 'w': w(); break;
            case 'e': e(); break;
            case 'r': r(); break;
            case 't': t(); break;
            case 'y': y(); break;
            case 'u': u(); break;
            case 'i': i(); break;
            case 'o': o(); break;
            case 'p': p(); break;
            case 'a': a(); break;
            case 's': s(); break;
            case 'd': d(); break;
            case 'f': f(); break;
            case 'g': g(); break;
            case 'h': h(); break;
            case 'j': j(); break;
            case 'k': k(); break;
            case 'l': l(); break;
            case 'z': z(); break;
            case 'x': x(); break;
            case 'c': _c(); break;
            case 'v': v(); break;
            case 'b': b(); break;
            case 'n': n(); break;
            case 'm': m(); break;
            case ' ': _space();  break; 
            case '0': _0(); break;
            case '1': _1(); break;
            case '2': _2(); break;
            case '3': _3(); break;
            case '4': _4(); break;
            case '5': _5(); break;
            case '6': _6(); break;
            case '7': _7(); break;
            case '8': _8(); break;
            case '9': _9(); break;
        }

        keyboard.buffer.pop();
    }

    lcd.clear();
    numOfChars = 0;
    attachInterrupt(digitalPinToInterrupt(clk_pin), ps2interrupt, FALLING);
}
