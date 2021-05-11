#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	Pair operator= (const Pair&);
	Pair operator++();
	Pair operator++(int);
	friend bool operator<(const Pair& p1, const Pair& p2) { return p1.first < p2.first; }
	friend bool operator>(const Pair& p1, const Pair& p2) { return p1.first > p2.first; }
	friend ostream& operator<< (ostream& out, const Pair& p);
	friend istream& operator>> (istream& in, Pair& p);
	friend fstream& operator>> (fstream& fin, Pair& p);
	friend fstream& operator<< (fstream& fout, const Pair& p);
	friend int change_file(const char*, int, int);
public:
	~Pair();
private:
	int first;
	double second;
};

