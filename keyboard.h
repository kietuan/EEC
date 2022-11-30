#ifndef PS2_KEYBOARD
#define PS2_KEYBOARD

#include <Arduino.h>
#include "LiquidCrystal.h"

#define PS2_KEYMAP_SIZE 38
#define CLK_PERIOD

class ps2keyboard;
ps2keyboard keyboard; //1 biến global dùng để lưu trữ 1 bàn phím hiện tại

template<typename T>
class queue //thêm vào tail, xóa ở head
{
    friend class ps2keyboard;
private:
    class node;

    node*  head{};
    node*  tail{};
    uint8_t size{};

public: //Methods
    queue(): head{nullptr}, tail{nullptr}; size{0} {}

    uint8_t getSize() const;
    T        front()   const;
    T        back()    const;
    bool     isEmpty() const;
private:
    void clear();
    void pop();
    void push(T value);
};

template<typename T>
class queue<T>::node
{
public:   
    T data{};
    node* next{};
    node (T value): data{value}, next{nullptr} {}
};



class ps2keyboard //object xử lý input
{
    friend void ps2interrupt();

    queue<uint8_t> buffer{}; //chứa các chữ đã được xử lý
public:
    //keyboard (uint8_t data_pin, uint8_t clk_pin);

    void    init(uint8_t data_pin, uint8_t clk_pin);
    void    push (uint8_t);
    void    clear();
    int     read(); //đọc ký tự tiếp theo chỉ khi gặp trúng được _ENTER
    uint8_t readScanCode() const;
    bool    available() const; //Nếu sẵn có chữ trong buffers để đọc


private:
};

void ps2interrupt();


#endif