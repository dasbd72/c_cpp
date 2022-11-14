#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll penalty = 0;
    ll time = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        time += A[i];
        penalty += time;
    }
    cout << penalty << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}