#include "Stack.h"

void Stack::make(int n) {
	int a;
	for (size_t i = 0; i < n; i++) {
		cout << "Ведите " << i << " элемент стека: ";
		cin >> a;
		st.push(a);
	}
}

void Stack::push() {
	int s = st2.size();
	for (size_t i = 0; i < s; i++) {
		st.push(st2.top());
		st2.pop();
	}
}

void Stack::print() {
	int s = st.size();
	cout << endl;
	if (s == 0)
		cout << "Стек пустой." << endl;
	else {
		for (size_t i = 0; i < s; i++) {
			cout << st.top() << " ";
			st2.push(st.top());
			st.pop();
		}
	}
	cout << endl;
	push();
}

void  Stack::del() {
	int s = st.size();
	for (size_t i = 0; i < s; i++) {
		if (st.top() % 2 != 0) {
			st2.push(st.top());
		}
		st.pop();
	}
	push();
}