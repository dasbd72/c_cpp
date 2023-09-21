#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int N, A, D;
    priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, greater<tuple<ll, ll>>> pq;  //  duration, deadline
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> D;
        pq.emplace(A, D);
    }

    ll prev = 0;
    ll reward = 0;
    while (!pq.empty()) {
        ll deadline, duration;
        tie(duration, deadline) = pq.top();
        pq.pop();
        prev += duration;
        reward += deadline - prev;
    }
    cout << reward << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 T3-0.cpp ; ./a.out <T3-0.in