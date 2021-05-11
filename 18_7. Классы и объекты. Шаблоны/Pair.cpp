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

Pair& Pair::operator = (const Pair& p) {
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator+ (Pair p) {
	int kf = first + p.first;
	double ks = second + p.second;
	Pair temp(kf, ks);
	return temp;
}

ostream& operator<< (ostream& out, const Pair& p) {
	out << p.first << " : " << p.second << " ";
	return out;
}

istream& operator >> (istream& in, Pair& p) {
	cout << "\nFirst: "; in >> p.first;
	cout << "\nSecond: "; in >> p.second;
	return in;
}