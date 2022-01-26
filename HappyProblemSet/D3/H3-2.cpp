#include <bits/stdc++.h>
using namespace std;
map<const char, const int> Nuc2Idx{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
map<const int, const char> Idx2Nuc{{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    for (cin >> T; T--;) {
        int M, N;
        cin >> M >> N;

        int ans = 0;
        string DNA;
        vector<array<int, 4>> nucleotides(N, {0, 0, 0, 0});
        string consensus(N, 'A');

        for (int i = 0; i < M; i++) {
            cin >> DNA;
            for (int j = 0; j < N; j++) nucleotides[j][Nuc2Idx[DNA[j]]]++;
        }

        for (int pos = 0; pos < N; pos++) {
            int maxIdx = 0, maxVal = 0;
            for (int i = 0; i < 4; i++) {
                if (nucleotides[pos][i] > maxVal) {
                    maxVal = nucleotides[pos][i];
                    maxIdx = i;
                }
            }
            consensus[pos] = Idx2Nuc[maxIdx];
            ans += M - maxVal;
        }
        cout << consensus << "\n"
             << ans << "\n";
    }
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H3-2.cpp ; ./a.out <H3-2.in