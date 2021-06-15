#include <bits/stdc++.h>
using namespace std;
struct comparitor {
    bool operator()(pair<int, int> pa, pair<int, int> pb) {
        if (pa.first < pb.first) return true;
        if (pa.first > pb.first) return false;
        if (pa.second < pb.second) return true;
        return false;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    vector<int> A(1000005);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparitor> Q;

    cin >> N >> L;
    for (int i = 1, x, j = 1; i <= N; i++) {
        cin >> x;
        Q.push(make_pair(x, i));
        if (i >= L) {
            cout << Q.top().first << " ";
            while (Q.top().second <= j) Q.pop();
            j++;
        }
    }
    cout << "\n";
}