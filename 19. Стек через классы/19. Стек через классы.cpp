#include <iostream>
#include "Stack.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Stack stack;
	int n;
	cout << "Введите размер стека: "; cin >> n;
	stack.make(n);
	stack.print();
	stack.del();
	cout << "Обновленный стек:";
	stack.print();
	system("pause");
	return 0;
}
