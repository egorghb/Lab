#include "Receipt.h"
//конструктор без параметров
Receipt::Receipt() {
	number = 0;
	date = "";
	sum = 0;
	cout << "Constructor without parameters" << this << endl;
}
//конструктор с параметрами
Receipt::Receipt(int N, string D, double S) {
	number = N;
	date = D;
	sum = S;
	cout << "Constructor with parameters" << this << endl;
}
//конструктор копирования
Receipt::Receipt(const Receipt& r) {
	number = r.number;
	date = r.date;
	sum = r.sum;
	cout << "Copy constructor" << this << endl;
}
//деструктор
Receipt::~Receipt() {
	cout << "Destructor for object" << this << endl;
}
//селекторы
int Receipt::get_number() {
	return number;
}

string Receipt::get_date() {
	return date;
}

double Receipt::get_sum() {
	return sum;
}
//модификаторы
void Receipt::set_number(int N) {
	number = N;
}

void Receipt::set_date(string D) {
	date = D;
}

void Receipt::set_sum(double S) {
	sum = S;
}
//метод для просмотра атрибутов
void Receipt::show() {
	cout << "Number: " << number << endl;
	cout << "Date: " << date << endl;
	cout << "Sum: " << sum << endl;
}
