#include "types.h"
#include <iostream>

int main() {
    // Проверка треугольника
    Triangle t1({0, 0}, {3, 0}, {0, 4});
    Triangle t2({1, 1}, {4, 1}, {1, 5});
    std::cout << "Triangle 1: " << t1 << '\n';
    std::cout << "Triangle 2: " << t2 << '\n';
    std::cout << "Triangle 1 == Triangle 2: " << (t1 == t2) << '\n';
    std::cout << "Triangle 1 < Triangle 2: " << (t1 < t2) << '\n';
    t1 += {1, 1};
    std::cout << "Triangle 1 after shifting: " << t1 << '\n';

    // Проверка очереди
    FIFOQueue queue;
    queue << 1 << 2 << 3;
    int value;
    queue >> value;
    std::cout << "Dequeued value: " << value << '\n';
    queue >> value;
    std::cout << "Dequeued value: " << value << '\n';
    queue >> value;
    std::cout << "Dequeued value: " << value << '\n';

    return 0;
}