#include <iostream>
#include <string>
using namespace std;

int n;

struct timetable {
    string starting_st;
    string end_st;
};

timetable* arr;

void create() {
    cout << "Введите количество рейсов: ";
    cin >> n;
    arr = new timetable[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {

        cout << "Введите станцию отправления " << i + 1 << " рейса: ";
        getline(cin, arr[i].starting_st);

        cout << "Введите конечную станцию " << i + 1 << " рейса: ";
        getline(cin, arr[i].end_st);

        cout << endl;
    }
    cout << "\nРасписание успешно составлено!\n";
}

void print() {
    if (n == 0) {
        cout << "Пусто.\n";
    }
    else {
        cout << endl;
        cout << "Ваше расписание:\n\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " рейс:\n";
            cout << "Станция отправления: " << arr[i].starting_st << endl;
            cout << "Конечная станция: " << arr[i].end_st << endl;
            cout << endl;
        }
    }
}

void shell_sort() {

}


int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    
    create();
    print();















    return 0;
}
