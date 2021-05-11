#include <iostream>
#include <list>
#include <algorithm>
#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
using namespace std;

typedef list<Pair> PList;
Pair p;

PList make_list(int n) {
    Pair a;
    PList l;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << endl;
        cin >> a;
        l.push_back(a);
    }
    return l;
}

void print_list(PList l) {
    PList::iterator it = l.begin();
    for (; it != l.end(); it++)
        cout << *it << endl;
    cout << endl;
}

Pair average(PList l) {
    PList::iterator it = l.begin();
    Pair p = *it;
    for (; it != l.end(); it++)
        p = p + *it;
    int n = l.size();
    return p / n;
}

struct Comp_less {
public:
    bool operator() (Pair p1, Pair p2) {
        if (p1 > p2) return true;
        else return false;
    }
};

struct Equal_p {
    bool operator() (const Pair& p_) {
        return p_ == p;
    }
};

void substr(Pair& p_) {
    p_ = p_ - p;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    PList l;
    l = make_list(n);
    print_list(l);
    PList::iterator i = l.begin();
    Pair k = average(l);
    cout << "Average = " << k << endl;
    int pos;
    cout << "Position = "; cin >> pos;
    advance(i, pos); 
    l.insert(i, k);
    print_list(l);
    cout << "Descending sort:" << endl;
    l.sort(Comp_less());
    print_list(l);
    cout << "Sort Ascending:" << endl;
    l.sort();
    print_list(l);
    cout << "Which element to remove: " << endl;
    cin >> p;
    l.remove_if(Equal_p());
    print_list(l);
    p = average(l);
    cout << "Average = " << p << endl;
    for_each(l.begin(), l.end(), substr);
    print_list(l);
    system("pause");
    return 0;
}
