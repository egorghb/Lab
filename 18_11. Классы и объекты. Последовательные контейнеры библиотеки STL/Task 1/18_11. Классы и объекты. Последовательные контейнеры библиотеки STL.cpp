#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef list<int> List;

List make_list(int n) {
    List l;
    srand(time(0));
    for (int i = 0; i < n; i++) {

        int a = rand() % 100 - 50;
        l.push_back(a);
    }
    return l;
}

void print_list(List l) {
    List::iterator it = l.begin();
    if (l.empty()) cout << "\nEmpty!\n";
    else for (; it != l.end(); it++) cout << *it << " ";
}

int average(List l) {
    int s = 0;
    List::iterator it = l.begin();
    for (; it != l.end(); it++) s += *it;
    int n = l.size();
    return s / n;
}

void add_list(List& l, int k, int pos) {
    List::iterator it = l.begin();
    for (int i = 0; i < pos; i++) it++;
    l.insert(it, k);
}

void del_list(List& l, int begin, int end) {
    List::iterator first = l.begin(), last = l.begin();;
    advance(first, begin);
    advance(last, end + 1);
    l.erase(first, last);
}

void substr_list(List& l, int k) {
    List::iterator it = l.begin();
    for (; it != l.end(); it++)
        *it -= k;
}

int main()
{
    try {
        list<int> l;
        list<int>::iterator li = l.begin();
        int n;
        cout << "N = "; cin >> n;
        l = make_list(n);
        print_list(l);
        int pos, k = average(l);
        cout << "\nPosition = "; cin >> pos;
        if (pos > l.size()) throw 1;
        add_list(l, k, pos);
        print_list(l);
        int first, last;
        cout << "\nElements from which range to remove?";
        cout << "\nFirst position: "; cin >> first;
        cout << "Last position: "; cin >> last;
        if (first < 0 || first > l.size() || last < 0 || last > l.size()) throw 1;
        del_list(l, first, last);
        print_list(l);
        cout << "\nSubstracting the arithmetic mean...\n";
        k = average(l);
        substr_list(l, k);
        print_list(l);
    }
    catch (int) {
        cout << "Error!";
    }
    cout << endl;
    system("pause");
    return 0;
}