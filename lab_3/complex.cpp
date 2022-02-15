#include "complex.h"


Complex::Complex(const double& Re_value, const double& Im_value) :Re(Re_value), Im(Im_value) { }

Complex operator+(const Complex& v1, const Complex& v2) {
	double Re_sum = v1.Re + v2.Re;
	double Im_sum = v1.Im + v2.Im;
	return Complex(Re_sum, Im_sum);
}

Complex operator-(const Complex& v1, const Complex& v2) {
	double Re_dif = v1.Re - v2.Re;
	double Im_dif = v1.Im - v2.Im;
	return Complex(Re_dif, Im_dif);
}

Complex operator*(const Complex& v1, const Complex& v2) {
	double Re_mult = v1.Re * v2.Re - v1.Im * v2.Im;
	double Im_mult = v1.Re * v2.Im + v1.Im * v2.Re;
	return Complex(Re_mult, Im_mult);
}

Complex operator/(const Complex& v1, const Complex& v2) {
	try {
		if (pow(v2.Re, 2) + pow(v2.Im, 2) == 0)
			throw exception("деление на ноль");
	}
	catch (const exception e) {
		cerr << "Ошибка при делении: " << e.what() << endl;
	}
	double Re_dev = (v1.Re * v2.Re + v1.Im * v2.Im) / (pow(v2.Re, 2) + pow(v2.Im, 2));
	double Im_dev = (v1.Im * v2.Re - v1.Re * v2.Im) / (pow(v2.Re, 2) + pow(v2.Im, 2));
	return Complex(Re_dev, Im_dev);
}

Complex operator^(const Complex& v, const int& n) {
	double r = sqrt(pow(v.Re, 2) + pow(v.Im, 2));
	double arg;
	if (v.Re == 0) {
		if (v.Im > 0)
			arg = PI / 2.;
		else if (v.Im < 0)
			arg = - PI / 2.;
		else
			return Complex(0, 0);
	}
	else
		arg = atan(v.Im / v.Re);
	double Re_pow = pow(r, n) * cos(n * arg);
	double Im_pow = pow(r, n) * sin(n * arg);
	return Complex(Re_pow, Im_pow);
}

ostream& operator<<(ostream& out, const Complex& v) {
	if (v.Im >= 0)
		out << v.Re << " + i" << v.Im;
	else
		out << v.Re << " - i" << abs(v.Im);
	return out;
}

bool operator==(const Complex& v1, const Complex& v2) {
	return round(v1.Re / PRECISION) == round(v2.Re / PRECISION) and 
		round(v1.Im / PRECISION) == round(v2.Im / PRECISION);
}

Complex sqrt(const Complex& v) {
	double r = sqrt(pow(v.Re, 2) + pow(v.Im, 2));
	double arg;
	if (v.Re == 0) {
		if (v.Im > 0)
			arg = PI / 2.;
		else if (v.Im < 0)
			arg = - PI / 2.;
		else
			return Complex(0, 0);
	}
	else
		arg = atan(v.Im / v.Re);
	double Re_pow = sqrt(r) * cos(1 / 2. * arg);
	double Im_pow = sqrt(r) * sin(1 / 2. * arg);
	return Complex(Re_pow, Im_pow);
}