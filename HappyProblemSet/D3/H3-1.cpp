#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int N, IDX = 1; cin >> N; IDX++) {
        if (N == 0)
            break;
        cout << "Game " << IDX << ":\n";

        vector<int> secret_code(N);
        vector<int> secret_cnt(10, 0);
        for (int i = 0; i < N; i++) {
            cin >> secret_code[i];
            secret_cnt[secret_code[i]]++;
        }
        while (true) {
            vector<int> guess_code(N);
            vector<int> guess_cnt(10, 0);
            int strong_match = 0, weak_match = 0;
            for (int i = 0; i < N; i++) {
                cin >> guess_code[i];
                if (guess_code[i] == secret_code[i])
                    strong_match++, weak_match--;
                guess_cnt[guess_code[i]]++;
                if (guess_cnt[guess_code[i]] <= secret_cnt[guess_code[i]])
                    weak_match++;
            }
            if (guess_code[0] == 0)
                break;
            cout << "    (" << strong_match << "," << weak_match << ")\n";
        }
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H3-1.cpp ; ./a.out <H3-1.in