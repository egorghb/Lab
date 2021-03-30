#pragma once
#include "Person.h"
class Student :
	public Person
{
public:
	Student(void);
public:
	~Student(void);
	void Show();
	Student(string, int, int);
	Student(const Student&);
	int get_years() { return years; }
	void set_years(int);
	Student& operator=(const Student&);
	friend istream& operator>> (istream& in, Student& s);
	friend ostream& operator<< (ostream& out, const Student& s);
protected:
	int years;
};

