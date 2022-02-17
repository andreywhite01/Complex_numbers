#pragma once

#include <iostream>
#include "complex.h"
#include <set>
using namespace std;

template <class T1, class T2>
void Assert(const T1& left, const T2& right, string hint) {
	if (!(left == right))
		cerr << "������ � ����� " << hint << ": " << left << " != " << right << endl;
	else
		cerr << "���� " << hint << " OK\n";
}
template <class T1, class T2>
void Assert(const set<T1>& left, const set<T2>& right, string hint) {
	if (!(left == right))
		cerr << "������ � ����� " << hint << ": " << left << " != " << right << endl;
	else
		cerr << "���� " << hint << " OK\n";
}
void Test();