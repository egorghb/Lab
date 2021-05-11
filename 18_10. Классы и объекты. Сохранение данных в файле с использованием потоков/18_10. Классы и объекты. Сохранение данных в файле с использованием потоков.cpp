#include "Pair.h"
#include "file_work.h"

int main()
{
    Pair p;
    int flag, c, k;
    char file_name[30];
    do {
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete record from file";
        cout << "\n4. Add record to file";
        cout << "\n5. Change record in file";
        cout << "\n0. Exit\n>";
        cin >> c;
        if (c != 0) {
            cout << "file name: "; cin >> file_name;
        }
        switch (c) {
        case 1: {
            flag = make_file(file_name);
            if (flag < 0) cout << "Can't make file";
            break;
        }
        case 2: {
            flag = print_file(file_name);
            if (flag == 0) cout << "Empty file\n";
            if (flag < 0) cout << "Can't read file\n";
            break;
        }
        case 3: {
            Pair m; cout << "Input pair:\n"; cin >> m;
            flag = del_file(file_name, m);
            if (flag < 0) cout << "Can't read file";
            break;
        }
        case 4: {
            int n;
            cout << "K = "; cin >> k;
            cout << "N = "; cin >> n;
            flag = add_file(file_name, k, n);
            if (flag < 0) cout << "Can't read file";
            if (flag == 0) add_end(file_name, k);
            break;
        }
        case 5: {
            int L;
            cout << "K = "; cin >> k;
            cout << "L = "; cin >> L;
            flag = change_file(file_name, k, L);
            if (flag < 0) cout << "Can't read file";
            if (flag == 0) cout << "\nNot such record";
            break;
        }
        }
    } while (c != 0);

    return 0;
}
