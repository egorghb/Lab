#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

int n;
string key;

struct User {
	string name;
	string data;
	long long number;
};

User* users_arr;

void correct_input(int& num) {
	cin >> num;
	while (num < 0) {
		cout << "Некорректный ввод. Введите заново: ";
		cin >> num;
	}
}

void create(User users_arr[], int& size) {
	cout << "Заполните данные о пользователях: \n";

	for (int i = 0; i < size; i++) {

		cout << "Введите имя пользователя: ";
		cin.ignore();
		getline(cin, users_arr[i].name);

		cout << "Введите дату рождения: ";
		getline(cin, users_arr[i].data);


		cout << "Введите номер телефона: ";
		cin >> users_arr[i].number;

		cout << endl;
	}
}



void print() {

	if (n == 0)
		cout << "Пусто.\n";
	else {
		cout << endl;
		cout << "Информация о пользователях:\n";

		for (int i = 0; i < n; i++) {

			cout << "ФИО: " << users_arr[i].name << endl;

			cout << "Дата рождения: " << users_arr[i].data << endl;

			cout << "Номер телефона: " << users_arr[i].number << endl;

			cout << endl;
		}
	}
}



void add_user() {
	int amount_of_new_users;
	cout << "Сколько пользователей необходимо добавить: ";
	cin >> amount_of_new_users;

	User* array_copy = new User[n + amount_of_new_users];
	create(array_copy, amount_of_new_users);

	for (int i = 0; i < n; i++) 

		array_copy[i + amount_of_new_users] = users_arr[i];

	n += amount_of_new_users;

	users_arr = array_copy;
}


void delete_user_number(User users_arr[], int k) {
	int i = 0;
	while (i < n) {
		if (i == k) {
			while (i < n - 1) {
				users_arr[i] = users_arr[i + 1];
				i++;
			}
			n--;
			User* array_copy = new User[n];

			for (int g = 0; g < n; g++)

				array_copy[g] = users_arr[g];

			users_arr = array_copy;
			break;
		}
		i++;
	}
}


void linesearch(User users_arr[], string key) {
	bool f = false;
	for (int i = 0; i < n; i++) {
		if (users_arr[i].name == key) {
			cout << "Пользователь находится в списке под номером: " << i + 1 << endl;
			f = true;
		}
	}
	if (!f)
		cout << "Пользователь не найден.";
}

void search(User users_arr[], string key) {
	string str;
	for (int i = 1; i <= n; i++) {
		str = str + to_string(i) + users_arr[i-1].name;
	}
	int strlen, keylen, res = -1;
	strlen = str.size();
	keylen = key.size();
	if (strlen != 0 && keylen != 0) {
		for (int i = 0; i < strlen - keylen + 1; i++) {
			for (int j = 0; j < keylen; j++) {
				if (key[j] != str[i + j])
					break;
				else if (j == keylen - 1) {
					res = i;
					break;
				}
			}
		}
	}
	if (res != -1)
		cout << "Пользователь найден! Он находится в списке под номером " << str[res - 1] << endl;
	else
		cout << "Пользователь не найден." << endl;
}

void sort_arr(User users_arr[]) {
	for (int i = 0; i < n - 1; i++) {  
		for (int j = n - 1; j >= (i + 1); j--) {  
			if (users_arr[j - 1].number > users_arr[j].number) {  
				User tmp = users_arr[j];
				users_arr[j] = users_arr[j - 1];
				users_arr[j - 1] = tmp;
			}
		}
	}
}

int interpolsearch(User users_arr[], long long int key_number) {
	int mid, left = 0, right = n - 1;
	while (users_arr[left].number <= key_number && users_arr[right].number >= key_number) {
		mid = left + ((key_number - users_arr[left].number) * (right - left)) / (users_arr[right].number - users_arr[left].number);
		if (users_arr[mid].number < key_number)
			left = mid + 1;
		else
			return mid;
	}
	if (users_arr[left].number == key_number)
		return left;
	else
		return -1;
}



int main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251");

	int a;

	cout << "Выберите действие:\n";
	cout << "1. Открыть файл.\n";
	cout << "2. Ввести список вручную.\n";
	cin >> a;
	if (a == 1) {
		int count = 0;
		string row;
		ifstream input;
		input.open("База данных.txt");
		while (!input.eof()) {
			count++;
			getline(input, row);
		}
		n = count / 4;
		users_arr = new User[n];
		input.close();
		input.open("База данных.txt");
		int i = 0;
		while (!input.eof() && n - i > 0) {
			getline(input, users_arr[i].name);
			getline(input, users_arr[i].data);
			getline(input, row);
			long long int x;
			istringstream(row) >> x;
			users_arr[i].number = x;
			getline(input, row);
			i++;
		}
		input.close();
		cout << "Список загружен.\n\n";
	}
	else {
		cout << "Введите количество пользователей: ";
		correct_input(n);

		users_arr = new User[n];
		create(users_arr, n);
		print();
	}

	while (true) {
		cout << "Выберите действие:\n";
		cout << "1. Добавить пользователей в список.\n";
		cout << "2. Удалить пользователя из списка.\n";
		cout << "3. Найти пользователя в списке.\n";
		cout << "4. Напечатать список.\n";
		cout << "5. Сохранить изменения в файл.\n";
		cout << "6. Выйти из программы.\n-->";

		cin >> a;

		switch (a) {
		case 1: {
			add_user();
			cout << "Пользователь добавлен.\n";
			break;
		}
		case 2: {
			int k;
			cout << "Введите номер пользователя в списке:\n";
			correct_input(k);
			delete_user_number(users_arr, k);
			cout << "Пользователь удален.\n";
			break;
		}
		case 3: {
			cout << "Каким методом искать:\n";
			cout << "1. Линейный метод.\n";
			cout << "2. Интерполяционный метод.\n";
			cout << "3. Прямой поиск подстроки в строке.\n-->";
			cin >> a;
			if (a != 2) {
				cout << "Введите ФИО пользователя: ";
				cin.ignore();
				getline(cin, key);
				if (a == 1)
					linesearch(users_arr, key);
				else
					search(users_arr, key);
			}
			else {
				cout << "Введите номер пользователя:\n";
				long long key_number;
				cin >> key_number;
				cout << "Сортируем список...\n";
				sort_arr(users_arr);
				int b = interpolsearch(users_arr, key_number);
				if (b != -1)
					cout << "Пользователь находится в списке под номером: " << b + 1 << endl;
				else
					cout << "Пользователь не найден." << endl;

			}
			break;
		}
		case 4:
			print();
			break;
		case 5: {
			ofstream output;
			output.open("База данных.txt");
			for (int i = 0; i < n; i++) {
				output << users_arr[i].name << "\n";
				output << users_arr[i].data << "\n";
				output << users_arr[i].number << "\n\n";
			}
			output.close();
			cout << "Изменения сохранены.\n\n";
			break;
		}
		case 6:
			exit(0);
		default: {
			cout << "Неверный номер действия.";
			break;
		}
		}
	}
	return 0;
}