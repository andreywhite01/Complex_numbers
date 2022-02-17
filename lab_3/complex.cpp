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
		out << round(v.Re / PRECISION) * PRECISION << " + " << round(v.Im / PRECISION)* PRECISION << "i";
	else
		out << round(v.Re / PRECISION) * PRECISION << " - " << round(abs(v.Im) / PRECISION) * PRECISION << "i";
	return out;
}

ostream& operator<<(ostream& out, const set<Complex>& s) {
	if (s.size() == 1) {
		return out << *(s.begin());
	}
	else {
		out << "[ ";
		auto it = s.begin();
		while(next(it) != s.end()) {
			out << *(it++) << ", ";
		}
		out << *prev(s.end()) << " ]";
		return out;
	}
}

bool operator==(const Complex& v1, const Complex& v2) {
	return round(v1.Re / PRECISION) == round(v2.Re / PRECISION) and 
		round(v1.Im / PRECISION) == round(v2.Im / PRECISION);
}

bool operator<(const Complex& v1, const Complex& v2) {
	if (v1.Re == v2.Re)
		return v1.Im <= v2.Im;
	else
		return v1.Re <= v2.Re;
}

set<Complex>sqrt(const Complex& v, const int& n) {
	set<Complex> results = {};
	double re = v.Re, im = v.Im, res_re, res_im;
	double r = sqrt(pow(re, 2) + pow(im, 2));
	double arg;
	if (re == 0) {
		if (im > 0)
			arg = PI / 2.;
		else if (im < 0)
			arg = -PI / 2.;
		else
			return set<Complex>{ Complex(0,0) };
	}
	else {
		if (re > 0)
			arg = atan(im / re);
		else if (re < 0) {
			if (im > 0)
				arg = atan(im / re) + PI;
			else if (im < 0)
				arg = atan(im / re) - PI;
			else
				arg = 0;
		}
		else
			arg = PI;
	}
	for (int k = 0; k < n; ++k) {
		res_re = pow(r, 1. / n) * cos((arg + 2. * PI * k) / n);
		res_im = pow(r, 1. / n) * sin((arg + 2. * PI * k) / n);
		results.insert(Complex(res_re, res_im));
	}
	return results;
}