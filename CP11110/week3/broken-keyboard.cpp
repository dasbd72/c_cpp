#include <bits/stdc++.h>
using namespace std;
void solve() {
    string S;
    while (getline(cin, S)) {
        list<char> output;
        auto it = output.begin();
        for(auto c : S) {
            if(c == '['){
                it = output.begin();
            } else if(c == ']') {
                it = output.end();
            } else {
                output.emplace(it, c);
            }
        }
        for(auto c : output) {
            cout << c;
        }
        cout << "\n";
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