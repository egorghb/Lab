#include "Pair.h"

//перегрузка операции присваивания
Pair& Pair:: operator= (const Pair& m) {
	//проверка на самоприсваивание
	if (&m == this) return *this;
	first = m.first;
	second = m.second;
	return *this;
}
//перегрузка префиксной операции инкремент
Pair& Pair:: operator++ () {
	++first;
	return *this;
}
//перегрузка постфиксной операции инкремент
Pair& Pair:: operator++ (int) {
	++second;
	return *this;
}

//перегрузка операции сравнения <
bool Pair:: operator < (const Pair& m) {
	if (first < m.first)
		return true;
	else
		return false
}
//перегрузка операции сравнения >
bool  Pair:: operator > (const Pair& m) {
	if (first > m.first)
		return true;
	else
		return false;
	
}

//перегрузка глобальной функции-операции ввода
istream& operator>> (istream& in, Pair& p) {
	cout << "first: "; in >> p.first;
	cout << "second: "; in >> p.second;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<< (ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}