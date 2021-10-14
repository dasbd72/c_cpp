#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    long long Ans;
    cin >> T;
    while (T--) {
        stack<pair<int, int>> A;
        Ans = 0;
        cin >> N;
        for (int i = 0, inp; i < N; i++) {
            cin >> inp;
            while (!A.empty() && inp > A.top().first) {
                Ans += A.top().second;
                A.pop();
            }
            if (!A.empty() && inp == A.top().first) {
                int cnt = A.top().second;
                A.pop();
                if (!A.empty()) Ans++;
                Ans += cnt;
                A.push(make_pair(inp, cnt + 1));
            } else {
                if (!A.empty()) Ans++;
                A.push(make_pair(inp, 1));
            }
        }
        cout << Ans << "\n";
    }
    return 0;
}