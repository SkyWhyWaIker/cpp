#include "types.h"
#include <cmath>

// Реализация функций для треугольника
Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {
    // Вычисление площади по формуле Герона
    double ab = std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
    double bc = std::sqrt(std::pow(c.x - b.x, 2) + std::pow(c.y - b.y, 2));
    double ac = std::sqrt(std::pow(c.x - a.x, 2) + std::pow(c.y - a.y, 2));
    double p = (ab + bc + ac) / 2;
    area = std::sqrt(p * (p - ab) * (p - bc) * (p - ac));
}

bool Triangle::operator==(const Triangle& other) const {
    return area == other.area;
}

bool Triangle::operator != (const Triangle& other) const {
    return !(*this == other);
}

bool Triangle::operator<(const Triangle& other) const {
    return area < other.area;
}

bool Triangle::operator>(const Triangle& other) const {
    return area > other.area;
}

void Triangle::operator+=(const Point& vector) {
    a.x += vector.x; a.y += vector.y;
    b.x += vector.x; b.y += vector.y;
    c.x += vector.x; c.y += vector.y;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    os << "Triangle: (" << triangle.a.x << ", " << triangle.a.y << "), ("
       << triangle.b.x << ", " << triangle.b.y << "), ("
       << triangle.c.x << ", " << triangle.c.y << ")";
    return os;
}

// Реализация функций для очереди
FIFOQueue& FIFOQueue::operator<<(int value) {
    if (!isFull()) {
        queue[rear] = value;
        rear = (rear + 1) % 100;
    }
    return *this;
}

FIFOQueue& FIFOQueue::operator>>(int& value) {
    if (!isEmpty()) {
        value = queue[front];
        front = (front + 1) % 100;
    }
    return *this;
}

bool FIFOQueue::isEmpty() const {
    return front == rear;
}

bool FIFOQueue::isFull() const {
    return (rear + 1) % 100 == front;
}
