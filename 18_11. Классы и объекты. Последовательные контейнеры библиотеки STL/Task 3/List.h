#pragma once
#include <list>
#include <iostream>
using namespace std;

template <class T>
class List {
	list<T> l;
	int len;
public:
	List(void);
	List(int n);
	void print();
	~List(void);
	T average();
	void add(T k, int pos);
	void del(int first, int last);
	void substraction(T k);
	int operator()() { return len; };
};

template <class T>
List<T>::List() {
	len = 0;
}

template <class T>
List<T>::~List(void) {}

template <class T>
List<T>::List(int n) {
	T a;
	cout << "Input list: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a;
		l.push_back(a);
	}
	len = l.size();
}

template <class T>
void List<T>::print() {
	typename list<T>::iterator it = l.begin();
	for (; it != l.end(); it++)
		cout << *it << "  ";
	cout << endl;
}

template <class T>
T List<T>::average() {
	typename list<T>::iterator it = l.begin();
	T s;
	for (; it != l.end(); it++)
		s = s + *it;
	return s / l.size();
}

template <class T>
void List<T>::add(T k, int pos) {
	typename list<T>::iterator it = l.begin();
	advance(it, pos);
	l.insert(it, k);
	len++;
}

template <class T>
void List<T>::substraction(T k) {
	typename list<T>::iterator it = l.begin();
	for (; it != l.end(); it++)
		*it = *it - k;
}

template <class T>
void List<T>::del(int first, int last) {
	typename list<T>::iterator it1 = l.begin();
	typename list<T>::iterator it2 = l.begin();
	advance(it1, first);
	advance(it2, last + 1);
	l.erase(it1, it2);
}