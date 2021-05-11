#include "Vector.h"
#include "Person.h"

Vector::~Vector(void) {
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n) {
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::add() {
	Object* p;
	cout << "1. Person" << endl;
	cout << "2. Employee" << endl;
	int y;
	cin >> y;
	if (y == 1) {
		Person* a = new (Person);
		a->input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2) {
			Emloyee* b = new Emloyee;
			b->input();
			p = b;
			if (cur < size) {
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}

void Vector::show() {
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->show();
		p++;
	}
}

int Vector::operator() () {
	return cur;
}

void Vector::del() {
	if (cur == 0) return;
	cur--;
}

void Vector::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		Object** p = beg;
		if (e.a >= 0 && e.a <= cur) {
			for (int i = 0; i < e.a; i++)
				p++;
		}
		(*p)->HandleEvent(e);
	}
}