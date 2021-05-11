#pragma once
#include <iostream>
using namespace std;

class Pair
{
	int first;
	double second;
public:
	Pair() { first = 0; second = 0.0; }
	Pair(int F, double S) { first = F; second = S; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int F) { first = F; }
	void set_second(double S) { second = S; }
	Pair operator+ (const Pair&);
	Pair operator/ (const int&);
	Pair operator- (const Pair&);
	Pair& operator= (const Pair&);
	friend bool operator< (const Pair&, const Pair&);
	friend bool operator> (const Pair&, const Pair&);
	friend bool operator== (const Pair&, const Pair&);
	friend istream& operator>> (istream&, Pair&);
	friend ostream& operator<< (ostream&, const Pair&);
};

