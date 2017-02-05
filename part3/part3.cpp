// part3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int getNOD(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	int X, Y, NOD;
	X = x;
	Y = y;
	do {
		NOD = X % Y;
		X = Y;
		Y = NOD;
	} while (x % NOD != 0 || y % NOD != 0);
	return NOD;
}

bool digitsAreDifferent(int n) {
	int a, b, c;
	//n = a * 100 + b * 10 + c
	a = n / 100;
	b = (n - a * 100) / 10;
	c = n - a * 100 - b * 10;
	return a != b && a != c && b != c;
}

int getIntSum(int n) {
	int sum = 0, x = 1;
	for (int i = 1; i <= n; i++) {
		sum += x;
		x += 2;
	}
	return sum;
}

double getDblSum(int n) {
	double sum = 0;
	double x;
	for (int i = 1; i <= n; i++) {
		x = 1.0 / i;
		sum += x;
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	int n, x = 1;
	//26
	cout << "Введите n\n";
	cin >> n;
	cout << "Все натуральные числа, меньшие n и взаимно простые с ним:\n";
	while (x < n) {
		if (getNOD(n, x) == 1) {
			cout << x << "; ";
		}
		x++;
	}

	//27
	cout << "\nВсе трехзначные числа, у которых нет одинаковых цифр:\n";
	for (int i = 100; i < 1000; i++) {
		if (digitsAreDifferent(i)) {
			cout << i << "; ";
		}
	}

	//28
	int A;
	x = 1;
	cout << "\nВведите A\n";
	cin >> A;
	while (x <= A) {
		x *= 2;
	}
	cout << "Первый член последовательности, превосходящий " << A << ": " << x << endl;

	//29 и 30
	cout << "Введите n\n";
	cin >> n;
	cout << "Сумма первых " << n << " членов ряда 1, 3, 5, 7, 9... = " << getIntSum(n) << endl;
	cout << "Сумма первых " << n << " членов ряда 1, 1/2, 1/3, 1/4... = " << getDblSum(n) << endl;
	
	return 0;
}

