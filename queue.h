
#ifndef QUEUE_
#define QUEUE_

#include <stdint.h>

template<typename T>
class queue //thêm vào tail, xóa ở head
{
private:
    class node;

    node*  head{};
    node*  tail{};
    uint8_t size{};

public: //Methods
    queue(): head{nullptr}, tail{nullptr}, size{0} {}

    uint8_t  getSize() const;
    T        front()   const; //xem ở đầu
    T        back()    const; //xem ở cuối
    bool     isEmpty() const;
    void     clear();
    void     pop_back();   //xóa ở cuối
    void     pop();        //xóa ở đầu
    void     push(T value); //thêm vào cuối
};

template<typename T>
class queue<T>::node
{
public:   
    T data{};
    node* next{};
    node (T value): data{value}, next{nullptr} {}
};

#endif