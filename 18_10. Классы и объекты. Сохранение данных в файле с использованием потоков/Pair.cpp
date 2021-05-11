#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0;
}

Pair::Pair(int F, double S) {
	first = F;
	second = S;
}

Pair::Pair(const Pair& p) {
	first = p.first;
	second = p.second;
}

Pair Pair::operator= (const Pair& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair:: operator++ () {
	++first;
	return *this;
}

Pair Pair:: operator++ (int) {
	++second;
	return *this;
}

Pair::~Pair () {}

ostream& operator<< (ostream& out, const Pair& p) {
	out << p.first << " : " << p.second << endl;
	return out;
}

istream& operator>> (istream& in, Pair& p) {
	cout << "First: "; in >> p.first;
	cout << "Second: "; in >> p.second;
	return in;
}

fstream& operator>> (fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator<< (fstream& fout, const Pair& p) {
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}