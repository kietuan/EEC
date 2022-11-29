#ifndef PS2_KEYBOARD
#define PS2_KEYBOARD

//#include <Arduino.h>
#define PS2_KEYMAP_SIZE 38
#define CLK_PERIOD

class Keyboard;
Keyboard keyboard; //1 biến global dùng để lưu trữ 1 bàn phím hiện tại

template<typename T>
class queue //thêm vào tail, xóa ở head
{
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



class Keyboard //object xử lý input
{
    friend void ps2interrupt();

    queue<uint8_t> buffer{}; //chứa các chữ đã được xử lý
public:
    //keyboard (uint8_t data_pin, uint8_t clk_pin);

    void    init(uint8_t data_pin, uint8_t clk_pin);
    bool    available() const; //Nếu sẵn có chữ trong buffers để đọc
    void    clear();
    int     read(); //đọc ký tự tiếp theo chỉ khi gặp trúng được _ENTER
    uint8_t readScanCode() const;

private:
};

void ps2interrupt();


#endif