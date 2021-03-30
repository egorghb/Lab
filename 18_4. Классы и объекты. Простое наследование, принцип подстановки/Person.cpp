#include "Person.h"

Person::Person(void)
{
	name = "";
	age = 0;
}
Person::~Person(void) {}
Person::Person(string N, int A)
{
	name = N;
	age = A;
}
Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}
void Person::set_name(string N)
{
	name = N;
}
void Person::set_age(int A)
{
	age = A;
}
Person& Person::operator=(const Person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}
istream& operator>>(istream& in, Person& p)
{
	cout << "\nName: "; in >> p.name;
	cout << "\nAge: "; in >> p.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& p)
{
	out << "\nNAME: " << p.name;
	out << "\nAGE: " << p.age;
	out << "\n";
	return out;
}
