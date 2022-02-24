#include "complex.h"


Complex::Complex(const double& Re_value, const double& Im_value) :Re(Re_value), Im(Im_value) { }

Complex operator+(const Complex& v1, const Complex& v2) {
	return Complex(v1.Re + v2.Re, 
		v1.Im + v2.Im);
}

Complex operator-(const Complex& v1, const Complex& v2) {
	return Complex(v1.Re - v2.Re, 
		v1.Im - v2.Im);
}

Complex operator*(const Complex& v1, const Complex& v2) {
	return Complex(v1.Re * v2.Re - v1.Im * v2.Im, 
		v1.Re * v2.Im + v1.Im * v2.Re);
}

Complex operator/(const Complex& v1, const Complex& v2) {
	try {
		if (pow(v2.Re, 2) + pow(v2.Im, 2) == 0)
			throw exception("деление на ноль");
	}
	catch (const exception e) {
		cerr << "Ошибка при делении: " << e.what() << endl;
	}
	return Complex((v1.Re * v2.Re + v1.Im * v2.Im) / (pow(v2.Re, 2) + pow(v2.Im, 2)),
		(v1.Im * v2.Re - v1.Re * v2.Im) / (pow(v2.Re, 2) + pow(v2.Im, 2)));
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
	return Complex(pow(r, n) * cos(n * arg), 
		pow(r, n) * sin(n * arg));
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