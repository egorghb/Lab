#include "Emloyee.h"

Emloyee::Emloyee(void) : Person() {
	rating = 0;
	position = "";
}

Emloyee::~Emloyee(void) {}

Emloyee::Emloyee(string N, int A, float R, string P) : Person(N, A)
{
	rating = R;
	position = P;
}

Emloyee::Emloyee(const Emloyee& e) {
	name = e.name;
	age = e.age;
	rating = e.rating;
	position = e.position;
}

void Emloyee::set_rating(float R) {
	rating = R;
}

void Emloyee::set_position(string P) {
	position = P;
}

Emloyee& Emloyee::operator= (const Emloyee& e) {
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	rating = e.rating;
	position = e.position;
}

void Emloyee::show() {
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nRating: " << rating;
	cout << "\nPosition: " << position;
	cout << endl;
}

void Emloyee::input() {
	cout << "\nName: "; cin >> name;
	cout << "\nAge: "; cin >> age;
	cout << "\nRating: "; cin >> rating;
	cout << "\nPosition: "; cin >> position;
}