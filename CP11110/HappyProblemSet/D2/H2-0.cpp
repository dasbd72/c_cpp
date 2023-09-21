#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    char prev_char = 0;
    int curr_len = 0;
    int max_len = numeric_limits<int>::min();
    for (auto c : S) {
        if (c == prev_char)
            curr_len++;
        else {
            prev_char = c;
            max_len = max(max_len, curr_len);
            curr_len = 1;
        }
    }
    max_len = max(max_len, curr_len);
    cout << max_len << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H2-0.cpp ; ./a.out <H2-0.in