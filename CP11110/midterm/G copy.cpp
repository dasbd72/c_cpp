#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cmp {
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first * a.second != b.first * b.second)
            return a.first * a.second < b.first * b.second;
        return a.first < b.first;
    }
};
ll score(priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> &heap) {
    ll maxVal = 0;
    if (!heap.empty()) {
        maxVal = max(maxVal, heap.top().first * heap.top().second);
    }
    return maxVal;
}
void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> F[i];
    sort(A.begin(), A.end(), less<ll>());
    sort(F.begin(), F.end(), greater<ll>());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> heap;
    for (int i = 0; i < N; i++)
        heap.emplace(A[i], F[i]);
    while (K > 0 && !heap.empty()) {
        auto tp = heap.top();
        heap.pop();
        if (heap.empty()) {
            tp.first -= K;
            K = 0;
        } else {
            ll dk = max(1LL, min(K, tp.first - (heap.top().first * heap.top().second) / tp.second));
            tp.first -= dk;
            K -= dk;
        }
        if (tp.first > 0)
            heap.push(tp);
    }
    cout << score(heap) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}