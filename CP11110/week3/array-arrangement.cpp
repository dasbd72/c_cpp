#include <bits/stdc++.h>
using namespace std;
void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;

        vector<list<int>::iterator> arr(N + 1);
        list<int> lst;
        for (int i = 0; i < N; i++) {
            lst.emplace_back(i + 1);
            arr[i + 1] = prev(lst.end());
        }	
        for (int q = 1; q <= Q; q++) {
            char c;
            int i;
            cin >> c >> i;
            auto it = arr[i];
            lst.erase(it);
            if(c == 'H') {
                lst.emplace_front(i);
                arr[i] = lst.begin();
            } else {
                lst.emplace_back(i);
                arr[i] = prev(lst.end());
            }
        }
        
        for (auto x : lst) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
// g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2
// g++ -std=c++17 -Wall -Wextra -g -O2
