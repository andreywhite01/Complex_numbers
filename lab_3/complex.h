#pragma once

#include <iostream>

#define PRECISION 1e-5
#define PI 3.14159265358979323846

using namespace std;

struct Complex {
	Complex(const double& Re_value = 0, const double& Im_value = 0);
	const double Re;
	const double Im;
};

// Перегрузка операторов + - * / ^ <<
Complex operator+(const Complex& v1, const Complex& v2);
Complex operator-(const Complex& v1, const Complex& v2);
Complex operator*(const Complex& v1, const Complex& v2);
Complex operator/(const Complex& v1, const Complex& v2);
Complex operator^(const Complex& v, const int& n);
bool operator==(const Complex& v1, const Complex& v2);
ostream& operator<<(ostream& out, const Complex& v);

// Перегрузка функции sqrt()
Complex sqrt(const Complex& v);