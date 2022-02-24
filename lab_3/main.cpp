#include <iostream>
#include "complex.h"
#include "testing.h"
#include <iterator>
#include <string>
using namespace std;

Complex GetComplexValue(string::const_iterator range_begin, string::const_iterator range_end);
set<Complex> Solve(const string& line);


int main() {
	setlocale(LC_ALL, "rus");
	Test();
	try
	{
		string line;
		cout << "Введите простейшее выражение с комплесными числами вида:\n";
		cout << "\t<(a + bi) % (c + di)>, где <%> -одна из операций +-/*\n";
		cout << "\t<(a + bi) ^ n>, где n - целое\n";
		cout << "\t<sqrt(a + bi)>\n\n";
		while (getline(cin, line)) {
			cout << "Ответ: " << Solve(line);
		}
	}
	catch (const exception& e)
	{
		cerr << "Произошла ошибка: " << e.what() << endl;
	}

	return 0;
}

set<Complex> Solve(const string &line) {
	auto range_begin1 = find(line.begin(), line.end(), '(');
	if (range_begin1 != line.end()) {
		auto range_end1 = find(next(range_begin1), line.end(), ')');
		if (range_end1 == line.end())
			throw(exception("Не найдена закрывающая скобка"));
		Complex value_1 = GetComplexValue(next(range_begin1), range_end1);
		auto range_begin2 = find(next(range_end1), line.end(), '(');
		if (range_begin2 == line.end()) {
			auto it_pow = find(next(range_end1), line.end(), '^');
			if (it_pow == line.end()) {
				string temp = { line.begin(), line.begin() + 4 };
				if (temp != "sqrt")
					return { value_1 };
				else
					return sqrt(value_1);
			}
			else {
				int pow = int(atof((string{ next(it_pow), line.end() }).c_str()));
				return { value_1 ^ pow };
			}
		}
		else {
			auto it_op = range_end1 += 2;
			char op = *(it_op);
			auto range_end2 = find(next(range_begin2), line.end(), ')');
			if (range_end2 == line.end())
				throw(exception("Не найдена закрывающая скобка"));
			else
			{
				Complex value_2 = GetComplexValue(next(range_begin2), range_end2);
				switch (op)
				{
				case '+': {
					return { value_1 + value_2 };
					break;
				}
				case '-': {
					return { value_1 - value_2 };
					break;
				}
				case '*': {
					return { value_1 * value_2 };
					break;
				}
				case '/': {
					return { value_1 / value_2 };
					break;
				}
				default:
					throw(exception("Не определена операция между компелксными числами"));
					break;
				}
			}
		}
	}
	else
		throw(exception("Не найдено комплексное число"));
}


Complex GetComplexValue(string::const_iterator range_begin, string::const_iterator range_end) {
	string re_v, im_v;
	auto it = range_begin;
	while (*it != ' ') {
		re_v += *(it++);
	}
	it++;
	while (*it != 'i') {
		if (*it != ' ')
			im_v += *it;
		++it;
	}
	if (it == range_end)
		throw(exception("Не найдено комплексное число"));
	double re = atof(re_v.c_str()),
		im = atof(im_v.c_str());
	return Complex(re, im);
}