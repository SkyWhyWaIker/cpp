#include "procedures.h"
#include <cmath>

void swap_pointers(int* a, int* b) {  // Меняет значения двух входных переменных друг на друга (указатели)
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_references(int& a, int& b) {  // Меняет значения двух входных переменных друг на друга (ссылки)
    int temp = a;
    a = b;
    b = temp;
}

void remove_fraction_pointers(double* num) {  // Отбрасывает от вещественного числа его дробную часть (указатели)
    *num = std::floor(*num);
}

void remove_fraction_references(double& num) {  // Отбрасывает от вещественного числа его дробную часть (ссылки)
    num = std::floor(num);
}

void multiply_complex_pointers(std::complex<double>* c, double* num) {  // Умножает комплексную переменную на второй аргумент процедуры – вещественное число (указатели)
    *c *= *num;
}

void multiply_complex_references(std::complex<double>& c, double& num) {  // Умножает комплексную переменную на второй аргумент процедуры – вещественное число (ссылки)
    c *= num;
}

void shift_circle_pointers(double* x, double* y, double* dx, double* dy) {  // Сдвигает окружность на заданный вектор (указатели)
    *x += *dx;
    *y += *dy;
}

void shift_circle_references(double& x, double& y, double& dx, double& dy) {  // Сдвигает окружность на заданный вектор (ссылки)
    x += dx;
    y += dy;
}