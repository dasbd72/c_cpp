#include <iostream>
#include <limits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string gear1, gear2;
    while (cin >> gear1 >> gear2) {
        int len1 = gear1.length();
        int len2 = gear2.length();
        int mincost;
        int len;
        mincost = numeric_limits<int>::max();
        for (int pos = -len2; pos < len1; pos++) {
            bool flag = true;
            int currlen;
            int currcost = 0;

            currlen = max(len1, len2 + pos) + (pos < 0 ? abs(pos) : 0);

            for (int p1 = 0; p1 < len1; p1++) {
                if (p1 - pos >= 0 && p1 - pos < len2) {
                    if (gear1[p1] == '2' && gear2[p1 - pos] == '2')
                        flag = false;
                    else if (gear1[p1] == '1' && gear2[p1 - pos] == '1')
                        currcost += 1;
                } else {
                    currcost += gear1[p1] == '1' ? 2 : 1;
                }
            }
            for (int p2 = 0; p2 < len2; p2++) {
                if (p2 + pos < 0 || p2 + pos >= len1) {
                    currcost += gear2[p2] == '1' ? 2 : 1;
                }
            }

            if (flag) {
                if (currcost < mincost) {
                    mincost = currcost;
                    len = currlen;
                }
            }
        }
        cout << len << '\n';
    }
    return 0;
}
// g++ -std=c++17 H0-4.cpp ; ./a.out <H0-4.in
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 H0-4.cpp ; ./a.out <H0-4.in