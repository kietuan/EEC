#include "keyboard.h"


//---------------------------------------------------------một số hàm của Queue----------------------------------------------------
template<typename T>
void queue<T>::push(T value) //thêm vào tail, xóa ở head
{
    auto p = new node(value);
    if (!head && !tail)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    size++;
}

template<typename T>
void queue<T>::pop()
{
    if (tail == head)
    {
        delete tail;
        tail = head = nullptr;
        size = 0;
    }
    else
    {
        auto temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

template<typename T>
T queue<T>::front() const
{
    return head->data;
}

template<typename T>
T queue<T>::back() const
{
    return tail->data;
}

template<typename T>
uint8_t queue<T>::getSize() const
{
    return this->size;
}

template<typename T>
bool queue<T>::isEmpty() const
{
    if (size == 0) return true;
    else           return false;
}


//----------------------------------------------------------------------hàm cho ps2keyboard-------------------------------------------------------------------
ps2keyboard::init (uint8_t data_pin, uint8_t clk_pin = 3) : buffer{}
{
    pinMode(clk_pin, INPUT_PULLUP);
    pinMode(data_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(clk_pin), ps2interrupt, FALLING);
}
 
void ps2keyboard::push(uint8_t scancode) //mỗi lần nhấn là phải đẩy lên màn hình, Nhận scancode, xuất ra mã ascii
{
    if (scancode == ) //nếu gặp enter thì đẩy ra hết
    {

    }
    else
    {

    }
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

