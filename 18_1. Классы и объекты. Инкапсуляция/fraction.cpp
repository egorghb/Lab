#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, int S) {
	while (F < 0 || S < 0) {
		cout << "Ошибка. Введено отрицательное число. Попробуйте ещё раз: ";
		cin >> F;
		cin >> S;
	}
	first = F;
	second = S;
}

void fraction::Read() {
	cout << "\nfirst? ";
	cin >> first;
	while (first < 0) {
		cout << "Ошибка. Введено отрицательное число. Попробуйте ещё раз: ";
		cin >> first;
	}
	cout << "\nsecond? ";
	cin >> second;
	while (second < 0) {
		cout << "Ошибка. Введено отрицательное число. Попробуйте ещё раз: ";
		cin >> first;
	}
}

void fraction::Show() {
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << endl;
}

double fraction::Summa() {
	return first * second;
}