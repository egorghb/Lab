#include "Receipt.h"
//����������� ��� ����������
Receipt::Receipt() {
	number = 0;
	date = "";
	sum = 0;
	cout << "Constructor without parameters" << this << endl;
}
//����������� � �����������
Receipt::Receipt(int N, string D, double S) {
	number = N;
	date = D;
	sum = S;
	cout << "Constructor with parameters" << this << endl;
}
//����������� �����������
Receipt::Receipt(const Receipt& r) {
	number = r.number;
	date = r.date;
	sum = r.sum;
	cout << "Copy constructor" << this << endl;
}
//����������
Receipt::~Receipt() {
	cout << "Destructor for object" << this << endl;
}
//���������
int Receipt::get_number() {
	return number;
}

string Receipt::get_date() {
	return date;
}

double Receipt::get_sum() {
	return sum;
}
//������������
void Receipt::set_number(int N) {
	number = N;
}

void Receipt::set_date(string D) {
	date = D;
}

void Receipt::set_sum(double S) {
	sum = S;
}
//����� ��� ��������� ���������
void Receipt::show() {
	cout << "Number: " << number << endl;
	cout << "Date: " << date << endl;
	cout << "Sum: " << sum << endl;
}
