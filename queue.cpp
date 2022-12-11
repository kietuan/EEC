#include"queue.h"

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
    if (size == 0) return;
    if (tail == head)
    {
        delete tail;
        tail = head = nullptr;
        size = 0;
    }
    else
    {
        T* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

template<typename T>
void queue<T>::pop_back()
{
    if (size == 0) return;
    if (tail == head)
    {
        delete tail;
        tail = head = nullptr;
        size = 0;
    }
    else
    {
        T* temp = head;
        while (temp->next != tail) temp = temp->next;

        delete tail;
        temp->next = nullptr;
        tail = temp;
        temp->next = nullptr;
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