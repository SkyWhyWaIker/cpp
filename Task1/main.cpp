// main.cpp
#include "procedures.h"
#include <iostream>
#include <complex>

int main() {
    int a = 5, b = 10;
    double num = 5.5;
    std::complex<double> c(1, 1);
    double x = 0, y = 0, dx = 1, dy = 2;

    // Проверка процедур с использованием указателей
    swap_pointers(&a, &b);
    remove_fraction_pointers(&num);
    multiply_complex_pointers(&c, &num);
    shift_circle_pointers(&x, &y, &dx, &dy);

    std::cout << "Checking procedures using pointers:" << '\n';
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "num = " << num << '\n';
    std::cout << "c = " << c << '\n';
    std::cout << "x = " << x << ", y = " << y << '\n';

    // Возвращаем значения переменных в исходное состояние для проверки ссылочных процедур
    a = 5, b = 10;
    num = 5.5;
    c = std::complex<double>(1, 1);
    x = 0, y = 0;

    // Проверка процедур с использованием ссылок
    swap_references(a, b);
    remove_fraction_references(num);
    multiply_complex_references(c, num);
    shift_circle_references(x, y, dx, dy);

    std::cout << "\nChecking procedures using links:" << '\n';
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "num = " << num << '\n';
    std::cout << "c = " << c << '\n';
    std::cout << "x = " << x << ", y = " << y << '\n';

    return 0;
}