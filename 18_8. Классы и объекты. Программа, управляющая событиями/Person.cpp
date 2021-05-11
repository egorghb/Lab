#include "Person.h"

Person::Person(void) {
	name = "";
	age = 0;
}

Person::~Person(void) {}

Person::Person(string N, int A) {
	name = N;
	age = A;
}

Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}

void Person::set_name(string N) {
	name = N;
}

void Person::set_age(int A) {
	age = A;
}

Person& Person:: operator= (const Person& p) {
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
}

void Person::show() {
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << endl;
}

void Person::input() {
	cout << "\nName: "; cin >> name;
	cout << "\nAge: "; cin >> age;
}

void Person::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command) {
		case cmGet: 
			cout << "Name: " << get_name() << endl;
			break;
		}
	}
}