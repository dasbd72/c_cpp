#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, s, d;
    cin >> n;
    while (n--) {
        cin >> s >> d;
        if (s >= d && (s - d) % 2 == 0)
            cout << (s + d) / 2 << ' ' << (s - d) / 2 << '\n';
        else
            cout << "impossible\n";
    }

    return 0;
}