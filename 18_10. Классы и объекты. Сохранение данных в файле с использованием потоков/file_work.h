#pragma once
#include "Pair.h"

int make_file(const char* f_name) {
	fstream stream(f_name, ios::out|ios::trunc); //открыть для записи
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "N = "; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;
	while (stream >> p) {
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Pair& m) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (!(p > m)) {
			temp << p;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, int n) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, f = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		while (i > n && k > 0) {
			Pair pp;
			cin >> pp;
			temp << pp;
			k--;
			f = 1;
			i++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return f;
}

int add_end(const char* f_name, int k) {
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	for (int i = k; i > 0; i--) {
		Pair pp;
		cin >> pp;
		stream << pp;
	}
	return 0;
}

int change_file(const char* f_name, int k, int L) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, c = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (p.first == k) {
			cout << p << " - is changing...";
			p.first += L;
			c++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return c;
}
