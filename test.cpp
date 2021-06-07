#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int> a, b;
    a.push_back(1);
    a.push_back(5);
    b = a;
    b.pop_front();
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : b) {
        cout << x << " ";
    }
    cout << endl;
}
