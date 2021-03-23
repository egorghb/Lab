#include "Receipt.h"

//функция для возврата объекта как результата
Receipt make_receipt() {
    int n;
    string d;
    double s;
    cout << "Введите номер квитанции: ";
    cin >> n;
    cout << "Введите дату: ";
    cin >> d;
    cout << "Введите сумму: ";
    cin >> s;
    Receipt r(n, d, s);
    return r;
}

//функция для передачи объекта как параметра
void print_receipt(Receipt r) {
    r.show();
}

int main()
{
    setlocale(LC_ALL, "Rus");
    //Constructor without parameters
    Receipt r1;
    r1.show();
    //Constructor with parameters
    Receipt r2(2, "01.03.2021", 12000);
    r2.show();
    //Copy constructor
    Receipt r3 = r2;
    r3.set_number(3);
    r3.set_date("01.02.2021");
    r3.set_sum(13500);
    //Copy constructor
    print_receipt(r3);
    //Copy constructor
    r1 = make_receipt();
    r1.show();
    return 0;
}