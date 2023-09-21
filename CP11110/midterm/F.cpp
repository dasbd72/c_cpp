#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    int maxpos;
    ll maxval = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > maxval) {
            maxval = A[i];
            maxpos = i;
        }
    }
    vector<int> ans(N);
    stack<pair<ll, ll>> stk;
    stk.emplace(maxval, maxpos);
    ans[maxpos] = maxpos;
    for (int i = maxpos + 1; i != maxpos; i = (i + 1) % N) {
        if (A[i] == maxval)
            ans[maxpos] = i;
    }
    if (N > 1)
        for (int i = (maxpos + 1) % N; i != maxpos; i = (i + 1) % N) {
            while (stk.top().first < A[i]) {
                stk.pop();
            }
            ans[i] = stk.top().second;
            stk.emplace(A[i], i);
        }
    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1;
        if (i == N - 1)
            cout << "\n";
        else
            cout << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}