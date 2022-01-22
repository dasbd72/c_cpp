#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    while (cin >> s) {
        double H, M;
        double deg_H, deg_M, diff;
        size_t pos;

        pos = s.find(':');
        H = stof(s.substr(0, pos));
        M = stof(s.substr(pos + 1, s.length() - pos));

        if (H == 0 && M == 0)
            break;
        H = H == 12 ? 0 : H;

        deg_M = 6.0 * M;
        deg_H = 30.0 * H + 0.5 * M;
        diff = abs(deg_M - deg_H);

        cout << fixed << setprecision(3) << (diff > 180 ? 360.0 - diff : diff) << '\n';
    }
    return 0;
}
// g++ -std=c++17 H0-1.cpp ; ./a.out <H0-1.in