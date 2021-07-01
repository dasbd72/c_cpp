#include <bits/stdc++.h>
using namespace std;
int main() {
    string op;
    multiset<int> minmax_heap;
    while (cin >> op) {
        if (op == "PUSH") {
            int k;
            cin >> k;
            minmax_heap.insert(k);
        } else if (op == "POPMIN") {
            if (!minmax_heap.empty()) {
                auto it = minmax_heap.begin();
                it++;
                minmax_heap.erase(minmax_heap.begin(), it);
            }
        } else if (op == "POPMAX") {
            if (!minmax_heap.empty()) {
                auto it = minmax_heap.end();
                it--;
                minmax_heap.erase(it, minmax_heap.end());
            }
        } else if (op == "MIN") {
            if (!minmax_heap.empty()) {
                cout << *minmax_heap.begin() << endl;
            } else {
                cout << "Null\n";
            }
        } else if (op == "MAX") {
            if (!minmax_heap.empty()) {
                auto it = minmax_heap.end();
                it--;
                cout << *it << endl;
            } else {
                cout << "Null\n";
            }
        } else if (op == "CLEAR") {
            minmax_heap.clear();
        }
    }
}