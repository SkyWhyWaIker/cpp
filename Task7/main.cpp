#include "CircularBuffer.h"
#include <iostream>

int main() {
    CircularBuffer<int> buffer(5);

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    buffer.push_front(0);

    buffer.insert(4, 3);

    buffer.pop_back();
    buffer.pop_front();

    std::cout << "First element: " << buffer.front() << '\n';
    std::cout << "Last element: " << buffer.back() << '\n';

    std::cout << "Element at index 1: " << buffer[1] << '\n';

    std::cout << "Buffer size: " << buffer.size() << '\n';
    std::cout << "Buffer capacity: " << buffer.capacity() << '\n';

    buffer.resize(10);

    std::cout << "Is buffer empty? " << (buffer.empty() ? "Yes" : "No") << '\n';

    return 0;
}