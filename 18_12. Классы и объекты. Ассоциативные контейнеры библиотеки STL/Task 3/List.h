#pragma once
#include <iostream>
#include <map>
using namespace std;

template <class T>
class Container {
	map<int, T> m;
	int len;
public:
	Container(void);
	Container(int n);
	void print();
	~Container(void);
	T average();
	void add(T k);
	void del(int, int);
	void substr(T k);
};

template <class T>
Container<T>::Container() {
	len = 0;
}

template <class T>
Container<T>::~Container(void) {}

template <class T>
Container<T>::Container(int n) {
	T a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		m[i] = a;
	}
	len = m.size();
}

template <class T>
void Container<T>::print() {
	typename map<int, T>::iterator i = m.begin();
	for (; i != m.end(); i++)
		cout << i->first << ": " << m[i->first] << endl;
}

template<class T>
T Container<T>::average() {
	T s;
	typename map<int, T>::iterator i = m.begin();
	for (; i != m.end(); i++)
		s = s + m[i->first];
	return s / m.size();
}

template<class T>
void Container<T>::add(T k) {
	int i = m.size();
	m.insert(make_pair(i, k));
}

template<class T>
void Container<T>::del(int first, int last) {
	for (int i = first; i <= last; i++) {
		if (m.find(i) != m.end()) {
			m.erase(m.find(i));
		}
	}
}

template<class T>
void Container<T>::substr(T k) {
	typename map<int, T>::iterator i = m.begin();
	for (; i != m.end(); i++)
		m[i->first] = m[i->first] - k;
}