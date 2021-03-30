#include "Pair.h"

int main() {
	setlocale(LC_ALL, "Russian");
	Pair a; //конструктор без параметров
	Pair b; //конструктор без параметров
	Pair c; //конструктор без параметров
	cin >> a; //ввод переменной
	cin >> b; //ввод переменной
	++a; //инкремент первого числа
	cout << a << endl; //вывод переменной
	c = a++; //конструктор копирования и инкремент второго числа
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	
	if (a > b)
		cout << "A > B";
	else
		cout << "A < B";
	
	return 0;
}