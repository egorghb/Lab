#include <iostream>
#include <map>
using namespace std;

typedef map<int, int>TMap;
typedef TMap::iterator it;

TMap make_map(int n) {
    TMap m;
    int a;
    for (int i = 0; i < n; i++) {
        cout << i << " = ";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_map(TMap m) {
    for (it i = m.begin(); i != m.end(); i++)
        cout << i->first << " : " << m[i->first] << endl;
}

int average(TMap m) {
    int s = 0;
    for (it i = m.begin(); i != m.end(); i++)
        s += m[i->first];
    return s / m.size();
}

void add(TMap& m, int k) {
    int i = m.size();
    m.insert(make_pair(i, k));
}

void del(TMap& m, int first, int last) {
    for (int i = first; i <= last; i++) {
        if (m.find(i) != m.end()) {
            m.erase(m.find(i));
        }
    }
}

void substr_map(TMap& m, int k) {
    for (it i = m.begin(); i != m.end(); i++)
        m[i->first] -= k;
}

int main()
{
    int n;
    cout << "N = "; cin >> n;
    TMap m = make_map(n);
    print_map(m);
    int k = average(m);
    cout << "Average = " << k << endl;
    add(m, k);
    print_map(m);
    int first, last;
    cout << "\nElements with keys from which range to remove?";
    cout << "\nFirst position: "; cin >> first;
    cout << "Last position: "; cin >> last;
    del(m, first, last);
    print_map(m);
    cout << "\nSubstracting the arithmetic mean...\n";
    k = average(m);
    cout << "Average = " << k << endl;
    substr_map(m, k);
    print_map(m);
    system("pause");
    return 0;
}
