#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    for (cin >> T; T--;) {
        string formula;
        map<char, int> atom;
        int prevPos = -1;
        double atomicWeight = 0;

        cin >> formula;
        for (int i = 0; i <= formula.length(); i++) {
            if (i == formula.length() || isalpha(formula[i])) {
                if (i > prevPos + 1)
                    atom[formula[prevPos]] += stoi(formula.substr(prevPos + 1, i - prevPos + 2));
                else
                    atom[formula[prevPos]]++;

                prevPos = i;
            }
        }

        atomicWeight += atom['C'] * 12.01;
        atomicWeight += atom['H'] * 1.008;
        atomicWeight += atom['O'] * 16.0;
        atomicWeight += atom['N'] * 14.01;
        cout << fixed << setprecision(3) << atomicWeight << '\n';
    }

    return 0;
}
// g++ -std=c++17 H0-3.cpp ; ./a.out <H0-3.in