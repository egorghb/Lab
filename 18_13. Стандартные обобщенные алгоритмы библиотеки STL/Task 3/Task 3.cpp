#include <iostream>
#include <algorithm>
#include <map>
#include "C:\Users\Acer\Desktop\GitHub\Task 2\Pair.h"
using namespace std;

typedef multimap<int, Pair> PMap;
typedef PMap::iterator it;
Pair p;

PMap make_map(int n) {
    Pair a;
    PMap m;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << endl;
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_map(PMap m) {
    cout << endl;
    for (it i = m.begin(); i != m.end(); i++)
        cout << i->first << " : " << i->second << endl;
    cout << endl;
}

Pair average(PMap m) {
    it i = m.begin();
    Pair p = i->second;
    for (; i != m.end(); i++)
        p = p + i->second;
    int n = m.size();
    return p / n;
}

struct Equal_p {
    bool operator() (const Pair& p_) {
        return p_ == p;
    }
};

void substr(pair<const int, Pair>& p_) {
    p_.second = p_.second - p;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    PMap m;
    m = make_map(n);
    print_map(m);
    p = average(m);
    cout << "Average = " << p << endl;
    int pos;
    cout << "Key = "; cin >> pos;
    m.insert(make_pair(pos, p));
    print_map(m);
    cout << "Which key to remove: " << endl;
    int key;
    cin >> key;
    while (m.count(key) > 0) {
        m.erase(key);
    }
    print_map(m);
    p = average(m);
    cout << "Average = " << p << endl;
    for_each(m.begin(), m.end(), substr);
    print_map(m);
    system("pause");
    return 0;
}