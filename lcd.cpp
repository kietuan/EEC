#include "lcd.h"

LiquidCrystal lcd(lcd_rs,lcd_e,lcd_d4,lcd_d5,lcd_d6,lcd_d7); //khởi tạo
queue<char> LCDqueue{};
uint8_t numOfChars = 0; //dùng để theo dõi số ký tự trên màn hình hiện tại

void readFromKeyboard()
{
    if (keyboard.available())
    {
        char character = keyboard.read();
        switch(character)
        {
            case 0x08: //xóa
                lcd.clear();
                LCDqueue.clear();
                break;
            case 0x0d: //gặp Enter, bắt đầu xả
                lcd.clear();
                lcd.print("PROCESSING...");
                transmitData(LCDqueue);
                lcd.clear();
                break;
            default: //thông thường, ghi lên màn hình
                if      (LCDqueue.getSize() % 32 == 0 ) lcd.clear();
                else if (LCDqueue.getSize() % 32 == 16) lcd.setCursor(0,1);
                LCDqueue.push(character);
                lcd.write(character);
                if (LCDqueue.getSize() == 64) //ngăn chặn overflow bộ nhớ
                {
                    lcd.clear();
                    lcd.print("PROCESSING...");
                    transmitData(LCDqueue);
                    lcd.clear();
                }
                break;
        }
    }
}

void transmitData(queue<char> &_q)
{
    detachInterrupt(digitalPinToInterrupt(clk_pin));
    while( !_q.isEmpty() )
    {
        char c = _q.front();
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

        _q.pop(); //cho tới khi hết
    }

    attachInterrupt(digitalPinToInterrupt(clk_pin), ps2interrupt, FALLING);
}