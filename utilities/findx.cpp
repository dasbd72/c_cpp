#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int x = 1; x <= 1800; x++) {
        if ((x - 3) % 8 == 0 && (x - 6) % 9 == 0 && (x - 7) % 25 == 0)
            cout << x << endl;
    }
}