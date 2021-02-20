#include <iostream>
#include <string>

using namespace std;

struct Film {

	string name;
	string director;
	int year;
	int cost;

};

Film* films;

const int amount_of_new_films = 1;

void input(int& k) {
	cin >> k;
	while (true) {
		if (k < 0) {
			cout << "Ошибка, введите ещё раз: ";
			cin >> k;
		}
		else
			break;
	}
}

void create(Film films_array[], int array_length) {

	cout << "Заполните данные о фильмах:\n";

	for (int i = 0; i < array_length; i++) {

		cout << "Введите название фильма: ";
		cin.ignore();
		getline(cin, films_array[i].name);

		cout << "Введите имя режиссера: ";
		getline(cin, films_array[i].director);


		cout << "Введите год выпуска: ";
		input(films_array[i].year);

		cout << "Введите стоимость фильма: ";
		input(films_array[i].cost);

		cout << endl;

	}

}

void print(int array_length) {

	if (array_length == 0)
		cout << "Пусто.\n";
	else {
		cout << endl;
		cout << "Информация о фильмах:\n";

		for (int i = 0; i < array_length; i++) {

			cout << "Название фильма: " << films[i].name << endl;

			cout << "Имя режиссера: " << films[i].director << endl;

			cout << "Год выпуска: " << films[i].year << endl;

			cout << "Стоимость: " << films[i].cost << endl;

			cout << endl;

		}

	}

}

void add_film(int& array_length) {

	Film* array_copy = new Film[array_length + amount_of_new_films];

	create(array_copy, amount_of_new_films);

	for (int i = 0; i < array_length; i++)

		array_copy[i + amount_of_new_films] = films[i];

	array_length += amount_of_new_films;

	films = array_copy;

}

void delete_film(int& array_length, int set_cost) {
	int i = 0;
	while (i < array_length) {
		bool f = false;
		if (films[i].cost > set_cost) {

			while (i < array_length - 1) {

				films[i] = films[i + 1];
				i++;
			}

			array_length--;

			Film* array_copy = new Film[array_length];

			for (int g = 0; g < array_length; g++)

				array_copy[g] = films[g];

			films = array_copy;
			f = true;
		}
		if (f)
			i = 0;
		else
			i = i + 1;
	}
}

int main()

{

	setlocale(LC_ALL, "rus");

	system("chcp 1251>nul");

	cout << "Введите количество фильмов: ";

	int amount_of_films = 0;

	input(amount_of_films);

	films = new Film[amount_of_films];

	create(films, amount_of_films);

	print(amount_of_films);

	cout << "Удаление фильма:\n";

	cout << "Введите заданную стоимость, не выше которой должен быть фильм: ";

	int set_cost;

	input(set_cost);

	delete_film(amount_of_films, set_cost);

	print(amount_of_films);

	cout << "Данные о следующих фильмах будут добавлены в базу данных:\n";

	add_film(amount_of_films);

	cout << "Содержимое базы данных после внесенных изменений:\n";

	print(amount_of_films);

	return 0;

}