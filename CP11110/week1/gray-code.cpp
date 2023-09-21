#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = n - 1; j >= 0; j--)
            cout << ((i + (1 << j)) / (1 << (j + 1))) % 2;
        cout << "\n";
    }
    return 0;
}