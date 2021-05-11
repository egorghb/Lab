#include "List.h"
#include "Error.h"

List::List(int s) {
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}

List::List(const List& l) {
	size = l.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = l.beg[i];
}

List::~List() {
	if (beg != 0) delete[] beg;
}

List::List(int s, int* mas) {
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}

const List& List::operator= (const List& l) {
	if (this == &l) return *this;
	if (beg != 0) delete[]beg;
	size = l.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = l.beg[i];
	return *this;
}

ostream& operator<< (ostream& out, const List& l) {
	if (l.size == 0) out << "Empty\n";
	else {
		for (int i = 0; i < l.size; i++)
			out << l.beg[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator>> (istream& in, List& l) {
	for (int i = 0; i < l.size; i++) {
		cout << ">";
		in >> l.beg[i];
	}
	return in;
}

int List::operator[] (int i) {
	if (i < 0) throw IndexError1();
	if (i >= size) throw IndexError2();
	return beg[i];
}

List List:: operator+ (int k) {
	for (int i = 0; i < size; i++) {
		beg[i] += k;
	}
	return *this;
}

List List::operator++ () {
	if (size == MAX_SIZE) throw MaxSizeError();
	List temp(size, beg);
	delete[]beg;
	size++;
	beg = new int[size];
	int k;
	cout << "¬ведите число: ";
	cin >> k;
	beg[size - 1] = k;
	for (int i = 0; i < size - 1; i++)
		beg[i] = temp.beg[i];
	return *this;
}