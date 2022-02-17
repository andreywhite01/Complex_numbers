#include "testing.h"

void Test() {
	{
		cerr << "Сложение\n";
		Assert((Complex(2, 7) + Complex(-3, -8)), Complex(-1, -1), "1");
		Assert((Complex(2, 7) + Complex(-2, -7)), Complex(0, 0), "2");
		Assert((Complex(-2, 7) + Complex(2, -7)), Complex(0, 0), "3");
		Assert((Complex(0, 0) + Complex(0, 0)), Complex(0, 0), "4");
		cerr << "Вычитание\n";
		Assert((Complex(2, 7) - Complex(-3, 8)), Complex(5, -1), "5");
		Assert((Complex(2, 7) - Complex(2, 7)), Complex(0, 0), "6");
		Assert((Complex(-2, 7) - Complex(2, -7)), Complex(-4, 14), "7");
		Assert((Complex(0, 0) - Complex(0, 0)), Complex(0, 0), "8");
		cerr << "Умножение\n";
		Assert((Complex(2, 7) * Complex(-3, 8)), Complex(-62, -5), "9");
		Assert((Complex(2, 7) * Complex(2, 7)), Complex(-45, 28), "10");
		Assert((Complex(-2, 1) * Complex(2, -1)), Complex(-3, 4), "11");
		Assert((Complex(0, 0) * Complex(0, 0)), Complex(0, 0), "12");
		cerr << "Деление\n";
		Assert((Complex(2, 2) / Complex(2, -1)), Complex(0.4, 1.2), "13");
		Assert((Complex(2, 7) / Complex(2, -4)), Complex(-1.2, 1.1), "14");
		Assert((Complex(-2, 1) / Complex(2, -1)), Complex(-1, 0), "15");
		Assert((Complex(0, 0) / Complex(1, 0)), Complex(0, 0), "16");
		Assert((Complex(0, 0) / Complex(1, 18)), Complex(0, 0), "17");
		cerr << "Возведение в целочисленную степень\n";
		Assert((Complex(2, 2) ^ 3), Complex(-16, 16), "18");
		Assert((Complex(1, -2) ^ 7), Complex(29, -278), "19");
		Assert((Complex(0, 0) ^ 4), Complex(0, 0), "20");
		Assert((Complex(0, -2) ^ 7), Complex(0, 128), "21");
		Assert((Complex(1.5, 0) ^ 3), Complex(3.375, 0), "22");
		Assert((Complex(-4, 1) ^ 2), Complex(15, -8), "23");
		cerr << "Извлечение квадратного корня\n";
		Assert(sqrt(Complex(1, 0)), set<Complex>{Complex(1, 0), Complex(-1, 0)}, "24");
		Assert(sqrt(Complex(0, 1)), set<Complex>{Complex(0.70711, 0.70711), Complex(-0.70711, -0.70711)}, "25");
		Assert(sqrt(Complex(-4,1)), set<Complex>{Complex(0.2481, 2.01533), Complex(-0.2481, -2.01533)}, "26");
		Assert(sqrt(Complex(0.1,2)), set<Complex>{Complex(1.0253, 0.97532), Complex(-1.0253, -0.97532)}, "27");
		Assert(sqrt(Complex(0,0)), set<Complex>{Complex(0, 0)}, "28");
		Assert(sqrt(Complex(-2, -3)), set<Complex>{Complex(0.89598, -1.67415), Complex(-0.89598, 1.67415)}, "29");
		Assert(sqrt(Complex(4, 2)), set<Complex>{Complex(2.05817, 0.48587), Complex(-2.05817, -0.48587)}, "30");
		Assert(sqrt(Complex(3, -3)), set<Complex>{Complex(1.90298, -0.78824), Complex(-1.90298, 0.78824)}, "31");
	}
}