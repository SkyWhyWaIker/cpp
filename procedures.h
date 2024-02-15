#ifndef FUNDAMENTAL_PROGRAMMING_CPP_PROCEDURES_H
#define FUNDAMENTAL_PROGRAMMING_CPP_PROCEDURES_H

#include <complex>

// Меняет значения двух входных переменных друг на друга (указатели)
void swap_pointers(int* a, int* b);

// Меняет значения двух входных переменных друг на друга (ссылки)
void swap_references(int& a, int& b);

// Отбрасывает от вещественного числа его дробную часть (указатели)
void remove_fraction_pointers(double* num);

// Отбрасывает от вещественного числа его дробную часть (ссылки)
void remove_fraction_references(double& num);

// Умножает комплексную переменную на второй аргумент процедуры – вещественное число (указатели)
void multiply_complex_pointers(std::complex<double>* c, double* num);

// Умножает комплексную переменную на второй аргумент процедуры – вещественное число (ссылки)
void multiply_complex_references(std::complex<double>& c, double& num);

// Сдвигает окружность на заданный вектор (указатели)
void shift_circle_pointers(double* x, double* y, double* dx, double* dy);

// Сдвигает окружность на заданный вектор (ссылки)
void shift_circle_references(double& x, double& y, double& dx, double& dy);

#endif //FUNDAMENTAL_PROGRAMMING_CPP_PROCEDURES_H
