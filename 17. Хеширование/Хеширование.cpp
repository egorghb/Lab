#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int choise;

struct Person {
	string FIO;
	string BDay;
	int Phone;
	Person* next;
};

void read(const int s, Person* st) {
	string a = "F1.txt";
	ifstream fin;
	fin.open(a, ios::in);
	if (!fin.is_open()) {
		cout << "Не удалось открыть файл";
	}
	else {
		cout << "Файл удалось открыть" << endl << endl;;
		for (int i = 0; i < s; i++) {
			getline(fin, st[i].FIO);
			getline(fin, st[i].BDay);
			string line2;
			getline(fin, line2);
			st[i].Phone = atoi(line2.c_str());
		}
	}
}

void print(Person* st, const int s) {
	for (int i = 0; i < s; i++) {
		cout << "ФИО: ";
		cout << st[i].FIO << endl;
		cout << "Дата рождения: ";
		cout << st[i].BDay << endl;
		cout << "Номер телефона: ";
		cout << st[i].Phone << endl;
		cout << '\n';
	}
}

int Hash_task(string row, int n)
{
	int x = 0;
	for (int i = 0; i < row.size(); i++)
		x += (int)(unsigned char(row[i]));
	cout << "ФИО: " << row << ", Hash = " << x % n << endl;
	return (x % n);
}

int Hash_quadro(string row, int n)
{
    int x = 0;
    int l;
    for (int i = 0; i < row.size(); i++) 
		x += (int)(unsigned char(row[i])) * (i + 1);
    x = x * x;
    l = to_string(x).size();
    return stoi(to_string(x).substr(l / 3, l * 2 / 3)) % n;
}

int Hash_ss(string row, int n)
{
    int x = 0;
    int result = 0;
    for (int i = 0; i < row.size(); i++) 
		x += (int)(unsigned char(row[i])) * (i + 1);
    for (int i = 0; i < to_string(x).size(); i++) 
		result += x / ((int)pow(10, i)) % 10 * ((int)pow(11, i));
	cout << "ФИО: " << row << ", Hash = " << result / 10 << endl;
    return result / 10 % n;
}

int SwitchHash(string row, const int s)
{
	switch (choise)
	{
	case 1:
		return Hash_task(row, s);
	case 2:
		return Hash_quadro(row, s);
	case 3:
		return Hash_ss(row, s);
	}
}

void Hash(Person* st, int s, Person* table) {
	for (int i = 0; i < s; i++) {
		table[i].FIO = "404";
	}
	int c = 0;
	double A = 0.0000015;
	for (int i = 0; i < s; i++) {
		int id = SwitchHash(st[i].FIO, s);                                   
		if (table[id].FIO == "404") {
			table[id].BDay = st[i].BDay;
			table[id].FIO = st[i].FIO;
			table[id].Phone = st[i].Phone;
			table[id].next = NULL;
		}
		else {
			c++;
			Person* elem = new Person;
			Person* p = &table[id];
			while (p->next != NULL) {
				p = p->next;
			}
			elem->BDay = st[i].BDay;
			elem->FIO = st[i].FIO;
			elem->Phone = st[i].Phone;
			p->next = elem;
			elem->next = NULL;
		}
	}
	cout << "Количество коллизий: " << c << endl;
}

void Find(int s, Person* table) {
	string key;
	cout << "Введите ФИО: " << endl;
	cin.get();
	getline(cin, key);
	double A = 0.0000015;
	int id = SwitchHash(key, s);
	cout << "Find id = " << id << endl;
	if (table[id].FIO == key) {
		cout << "ФИО: ";
		cout << table[id].FIO << endl;
		cout << "Дата рождения: ";
		cout << table[id].BDay << endl;
		cout << "Номер телефона: ";
		cout << table[id].Phone << endl;
		cout << '\n';
	}
	else if (table[id].FIO != key && table[id].next != NULL) {
		Person* p = table[id].next;
		bool f = true;
		while (p != NULL && f) {
			if (p->FIO == key) {
				cout << "ФИО: ";
				cout << p->FIO << endl;
				cout << "Дата рождения: ";
				cout << p->BDay << endl;
				cout << "Номер телефона: ";
				cout << p->Phone << endl;
				cout << '\n';
				f = false;
			}
			p = p->next;
		}
	}
	else {
		cout << "Такого элемента нет" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int s = 11;
	Person* st = new Person[s];
	Person* table = new Person[s];
	read(s, st);
	print(st, s);
	cout << "Выберите каким методом хешировать данные:\n";
	cout << "1. Метод остатков от деления.\n";
	cout << "2. Метод середины квадрата.\n";
	cout << "3. Метод перевода в другую систему счисления.\n-->";
	cin >> choise;
	Hash(st, s, table);
	Find(s, table);
	return 0;
}