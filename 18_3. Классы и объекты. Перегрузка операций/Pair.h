#pragma once
#include <iostream>
using namespace std;

class Pair {
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; }
	Pair(int f, double s) { first = f; second = s; }
	Pair(const Pair& m) { first = m.first; second = m.second; }
	~Pair() {}
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int f) { first = f; }
	void set_second(double s) { second = s; }
	//перегруженные операции
	Pair& operator= (const Pair&);
	Pair& operator++();
	Pair& operator++(int); //постфиксная операция
	
	bool operator<(const Pair& m);
	bool operator>(const Pair& m);
	
	//глобальные функции ввода-вывода
	friend istream& operator>> (istream&in, Pair& m);
	friend ostream& operator<< (ostream&out, const Pair& m);
};