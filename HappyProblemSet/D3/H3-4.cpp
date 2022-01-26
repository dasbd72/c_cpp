#include <bits/stdc++.h>
using namespace std;
string reverse(string num);
string stradd(string x, string y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    for (cin >> N; N--;) {
        string X, Y;
        cin >> X >> Y;
        cout << reverse(stradd(reverse(X), reverse(Y))) << "\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H3-4.cpp ; ./a.out <H3-4.in
string reverse(string num) {
    if (num == "0")
        return "0";
    stringstream ss;
    string ret;
    auto rit = num.rbegin();
    while (*rit == '0') ++rit;
    while (rit != num.rend()) {
        ss << *rit;
        ++rit;
    }
    ss >> ret;
    return ret;
}
string stradd(string x, string y) {
    string ret;
    int carry = 0, value;
    auto ritx = x.rbegin(), rity = y.rbegin();
    while (ritx != x.rend() && rity != y.rend()) {
        value = (*ritx - '0') + (*rity - '0') + carry;
        carry = value / 10;
        ret.push_back(value % 10 + '0');
        ++ritx, ++rity;
    }
    while (ritx != x.rend()) {
        value = (*ritx - '0') + carry;
        carry = value / 10;
        ret.push_back(value % 10 + '0');
        ++ritx;
    }
    while (rity != y.rend()) {
        value = (*rity - '0') + carry;
        carry = value / 10;
        ret.push_back(value % 10 + '0');
        ++rity;
    }
    if (carry)
        ret.push_back(carry + '0');
    return reverse(ret);
}