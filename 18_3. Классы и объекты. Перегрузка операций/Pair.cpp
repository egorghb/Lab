#include "Pair.h"

//���������� �������� ������������
Pair& Pair:: operator= (const Pair& m) {
	//�������� �� ����������������
	if (&m == this) return *this;
	first = m.first;
	second = m.second;
	return *this;
}
//���������� ���������� �������� ���������
Pair& Pair:: operator++ () {
	++first;
	return *this;
}
//���������� ����������� �������� ���������
Pair& Pair:: operator++ (int) {
	++second;
	return *this;
}

//���������� �������� ��������� <
bool Pair:: operator < (const Pair& m) {
	if (first < m.first)
		return true;
	else
		return false
}
//���������� �������� ��������� >
bool  Pair:: operator > (const Pair& m) {
	if (first > m.first)
		return true;
	else
		return false;
	
}

//���������� ���������� �������-�������� �����
istream& operator>> (istream& in, Pair& p) {
	cout << "first: "; in >> p.first;
	cout << "second: "; in >> p.second;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<< (ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}