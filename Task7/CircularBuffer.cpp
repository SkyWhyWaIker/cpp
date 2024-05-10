#include "CircularBuffer.h"

template<typename T>
CircularBuffer<T>::CircularBuffer(size_t size) : buffer(new T[size]), head(0), tail(0), max_size(size), full(false) {}

template<typename T>
CircularBuffer<T>::~CircularBuffer() {
    delete[] buffer;
}

template<typename T>
void CircularBuffer<T>::push_back(const T& item) {
    buffer[tail] = item;
    if (full) {
        head = (head + 1) % max_size;
    }
    tail = (tail + 1) % max_size;
    full = head == tail;
}

template<typename T>
void CircularBuffer<T>::push_front(const T& item) {
    head = (head - 1 + max_size) % max_size;
    buffer[head] = item;
    if (full) {
        tail = (tail - 1 + max_size) % max_size;
    }
    full = head == tail;
}

template<typename T>
void CircularBuffer<T>::insert(const T& item, size_t index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    size_t pos = (head + index) % max_size;
    buffer[pos] = item;
}

template<typename T>
void CircularBuffer<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    full = false;
    tail = (tail - 1 + max_size) % max_size;
}

template<typename T>
void CircularBuffer<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    full = false;
    head = (head + 1) % max_size;
}

template<typename T>
T& CircularBuffer<T>::front() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    return buffer[head];
}

template<typename T>
T& CircularBuffer<T>::back() {
    if (empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    return buffer[(tail - 1 + max_size) % max_size];
}

template<typename T>
T& CircularBuffer<T>::operator[](size_t index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[(head + index) % max_size];
}

template<typename T>
size_t CircularBuffer<T>::size() const {
    if (full) {
        return max_size;
    }
    if (head <= tail) {
        return tail - head;
    }
    return max_size - (head - tail);
}

template<typename T>
size_t CircularBuffer<T>::capacity() const {
    return max_size;
}

template<typename T>
void CircularBuffer<T>::resize(size_t new_size) {
    T* new_buffer = new T[new_size];
    size_t old_size = size();
    for (size_t i = 0; i < old_size && i < new_size; ++i) {
        new_buffer[i] = buffer[(head + i) % max_size];
    }
    delete[] buffer;
    buffer = new_buffer;
    head = 0;
    tail = old_size;
    max_size = new_size;
    full = old_size == new_size;
}

template<typename T>
bool CircularBuffer<T>::empty() const {
    return (!full && head == tail);
}

template class CircularBuffer<int>;
