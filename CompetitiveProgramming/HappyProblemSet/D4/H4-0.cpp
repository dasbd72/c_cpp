#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
    if (n == 0)
        return 1;
    int ret = 1;
    for (int i = 1; i <= n; i++) ret *= i;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    map<char, int> cnt;
    int k;
    cin >> S;
    sort(S.begin(), S.end());
    for (auto c : S)
        cnt[c]++;
    k = factorial(S.length());
    for (char c = 'a'; c <= 'z'; c++)
        k /= factorial(cnt[c]); 
    cout << k << "\n";
    do {
        cout << S << "\n";
    } while (next_permutation(S.begin(), S.end()));
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H4-0.cpp ; ./a.out <H4-0.in