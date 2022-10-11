#include <bits/stdc++.h>
using namespace std;
typedef tuple<string, int, unsigned int> mytype;

int trans_pos(string position) {
    int p;
    if (position == "elder") {
        p = 1;
    } else if (position == "nursy") {
        p = 2;
    } else if (position == "kit") {
        p = 3;
    } else if (position == "warrior") {
        p = 4;
    } else if (position == "appentice") {
        p = 5;
    } else if (position == "medicent") {
        p = 6;
    } else if (position == "deputy") {
        p = 7;
    } else {
        p = 8;
    }
    return p;
}
bool compare(mytype a, mytype b) {
    auto [an, ap, aa] = a;
    auto [bn, bp, ba] = b;
    if (ap != bp)
        return ap < bp;
    if (aa != ba) {
        if(ap == 5)
            return aa < ba;
        else
            return aa > ba;
    }
    return an < bn;
}
void solve() {
    int N, M;
    while (cin >> N >> M) {
        vector<mytype> vec;
        for (int i = 0; i < N; i++) {
            string name, position;
            unsigned int age;
            cin >> name >> position >> age;
            vec.emplace_back(name, trans_pos(position), age);
        }
        sort(vec.begin(), vec.end(), compare);
        for (int i = 0; i < M && i < N; i++) {
            cout << get<0>(vec[i]) << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2