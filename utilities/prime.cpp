#include <bits/stdc++.h>
using namespace std;
void allfactor(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            cout << i << ' ';
        }
    }
}
int main() {
    allfactor(779);
}