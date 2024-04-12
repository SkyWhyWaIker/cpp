#ifndef TYPES_H
#define TYPES_H

#include <iostream>

// Треугольник на плоскости
struct Point {
    double x, y;
};

class Triangle {
private:
    Point a, b, c;
    double area;

public:
    Triangle(Point a, Point b, Point c);
    bool operator==(const Triangle& other) const;
    bool operator!=(const Triangle& other) const;
    bool operator<(const Triangle& other) const;
    bool operator>(const Triangle& other) const;
    void operator+=(const Point& vector);
    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
};

// FIFO очередь целых чисел
class FIFOQueue {
private:
    int queue[100];
    int front, rear;

public:
    FIFOQueue() : front(0), rear(0) {}
    FIFOQueue& operator<<(int value);
    FIFOQueue& operator>>(int& value);
    bool isEmpty() const;
    bool isFull() const;
};

#endif // TYPES_H