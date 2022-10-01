#include <bits/stdc++.h>
using namespace std;
int t, n;
int x[15];
int choice;



int solve() {
    while(cin >> t >> n) {
        if(t == 0 && n == 0) 
            break;
        for(int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n, greater<int>());
        
        cout << "Sums of " << t << ":\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2