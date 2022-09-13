#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    std::string S;

    std::cin >> n;
    std::cin >> S;

    int i = 0;
    char prev = S[0];
    int cnt = 1;
    for (i = 1; i < n; i++) {
        if (prev != S[i]) {
            if(prev == '1')
                std::cout << cnt;
            cnt = 0;
        }
        cnt++;
        if(S[i] == '0'){
            if(cnt > 1)
                std::cout << '0';
        }

        prev = S[i];
    }
    if(prev == '1')
        std::cout << cnt;
    else if(prev == '0')
        std::cout << '0';
    std::cout << "\n";

    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 A.cpp