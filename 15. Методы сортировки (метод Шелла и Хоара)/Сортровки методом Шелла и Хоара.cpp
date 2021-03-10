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
    int d = n / 2;
    while (d > 0) {
        for (int i = d; i < n; i += d) {  // проходим по массиву, начиная со d элемента
            int j = i - d;   // присваиваем j номер предыдущего элемента перед a[i]
            timetable y = arr[i];    // присваиваем y сравниваемый элемент массива
            bool f = false;  // инициализируем флажок
            while ((j >= 0) && (!f)) {
                bool f2 = false;
                int z = 0;
                while (!f2 && arr[j].end_st.size() > z && y.end_st.size() > z) {
                    if ((int)(unsigned char(arr[j].end_st[z])) > (int)(unsigned char(y.end_st[z])))
                        f2 = true;
                    else if ((int)(unsigned char(arr[j].end_st[z])) == (int)(unsigned char(y.end_st[z])))
                        z++;
                    else break;
                }
                if (f2) {   // проверяем условие
                    arr[j + d] = arr[j];   // перемещаем элемент массива на d вправо
                    j = j - d;   // переходим к предыдущему элементу
                }
                else {
                    f = true;  // меняем значение флажка, так как нашли нужный элемент массива
                }
                arr[j + d] = y;   // ставим элемент массива в нужное место
            }
        }
        d /= 2;
    }
}
/*
bool comprasion(int& num, string x) {
    int z = 0;
    while (arr[num].end_st.size() > z && x.size() > z) {
        if ((int)(unsigned char(arr[num].end_st[z])) > (int)(unsigned char(x[z])))
            return true;
        else if ((int)(unsigned char(arr[num].end_st[z])) == (int)(unsigned char(x[z])))
            z++;
        else break;
    }
}*/

void hoare_sort(timetable* arr,int first, int last) {

    int i = first, j = last;
    timetable tmp;
    string x = arr[(first + last) / 2].end_st;

    do {
        while ((int)(unsigned char(arr[i].end_st[0])) < (int)(unsigned char(x[0])))
            i++;
        while ((int)(unsigned char(arr[j].end_st[0])) > (int)(unsigned char(x[0])))
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoare_sort(arr, i, last);
    if (first < j)
        hoare_sort(arr, first, j);
}



int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    
    create();
    print();
    
    int a;
    cout << "Каким методом сортировать?\n";
    cout << "1. Метод Шелла.\n";
    cout << "2. Метод Хоара.\n--> ";
    cin >> a;

    if (a == 1)
        shell_sort();
    else if (a == 2)
        hoare_sort(arr, 0, n - 1);
    else
        cout << "Неправильный номер.\n";

    cout << "Расписание после сортировки:\n";
    print();

    return 0;
}
