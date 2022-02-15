#pragma once

#include <iostream>
#include "complex.h"
using namespace std;

template <class T1, class T2>
void Assert(const T1& left, const T2& right, string hint) {
	if (!(left == right))
		cerr << "������ � ����� " << hint << ": " << left << " != " << right << endl;
	else
		cerr << "���� " << hint << " OK\n";
}
void Test();