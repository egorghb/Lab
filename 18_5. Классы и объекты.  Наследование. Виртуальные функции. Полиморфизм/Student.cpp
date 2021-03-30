#include "Student.h"
Student::Student(void) :Person()
{
	years = 0;
}
Student::~Student(void) {}
Student::Student(string N, int A, int Y) : Person(N, A)
{
	years = Y;
}
Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	years = s.years;
}
void Student::set_years(int Y)
{
	years = Y;
}
Student& Student::operator=(const Student& s)
{
	if (&s == this) return *this;
	name = s.name;
	age = s.age;
	years = s.years;
	return *this;
}
istream& operator>>(istream& in, Student& s)
{
	cout << "\nName: "; in >> s.name;
	cout << "\nAge: "; in >> s.age;
	cout << "\nYears: "; in >> s.years;
	return in;
}
ostream& operator<<(ostream& out, const Student& s)
{
	out << "\nNAME: " << s.name;
	out << "\nAGE: " << s.age;
	out << "\nYEARS: " << s.years;
	out << "\n";
	return out;
}
void Student::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
	cout << "YEARS: " << years;
	cout << "\n";
}