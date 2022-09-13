#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    std::string s, t;

    std::cin >> s >> t;

    int len_s = s.size();
    int len_t = t.size();
    int cnt_blank = 0;
    int cnt_s_alphabet[26] = {0};
    std::stack<char> stk;

    for (int i = 0; i < len_s; i++) {
        if (s[i] != '?')
            cnt_s_alphabet[s[i] - 'a']++;
        else
            cnt_blank++;
    }

    int si = 0, ti = 0;
    while (si < len_s) {
        if (cnt_s_alphabet[t[ti] - 'a'] > 0)
            cnt_s_alphabet[t[ti] - 'a']--;
        else if (cnt_blank) {
            stk.push(t[ti]);
            cnt_blank--;
        }

        si++;
        ti = (ti + 1) % len_t;
    }

    for (int si = 0; si < len_s; si++) {
        if (s[si] == '?') {
            std::cout << stk.top();
            stk.pop();
        } else {
            std::cout << s[si];
        }
    }
    std::cout << "\n";
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 D.cpp ; ./a.out <D.in
// g++ -std=c++17 -Wall -Wextra -g -O2 D.cpp ; ./a.exe