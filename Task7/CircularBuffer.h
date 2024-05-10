#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdexcept>

template<typename T>
class CircularBuffer {
private:
    T* buffer;
    size_t head;
    size_t tail;
    size_t max_size;
    bool full;

public:
    CircularBuffer(size_t size);
    ~CircularBuffer();

    void push_back(const T& item);
    void push_front(const T& item);
    void insert(const T& item, size_t index);
    void pop_back();
    void pop_front();
    T& front();
    T& back();
    T& operator[](size_t index);
    size_t size() const;
    size_t capacity() const;
    void resize(size_t new_size);
    bool empty() const;
};

#endif