#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string op;
    set<int> aiset;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "insert") {
            int ai;
            cin >> ai;
            aiset.insert(ai);
        } else if (op == "print") {
            if (!aiset.empty()) {
                for (auto it = aiset.begin(); it != aiset.end(); it++) {
                    if (it != aiset.begin()) cout << " ";
                    cout << *it;
                }
                cout << "\n";
            }
        } else if (op == "min") {
            if (!aiset.empty())
                cout << *aiset.begin() << "\n";
        } else if (op == "range_erase") {
            int l, r;
            cin >> l >> r;
            for (; l <= r; l++) aiset.erase(l);
        }
    }
}