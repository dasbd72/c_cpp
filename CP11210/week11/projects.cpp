#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int lowbit(int x) {
    return x & -x;
}
/* 1-based */
class BIT {
    int n;
    vector<ll> buf;

   public:
    void init(int _n) {
        n = _n;
        buf.resize(n + 1);
    }
    ll query(int x) const {
        ll sum = 0;
        for (; x; x -= lowbit(x))
            sum = max(sum, buf[x]);
        return sum;
    }
    void modify(int x, ll val) {
        for (; x <= n; x += lowbit(x))
            buf[x] = max(buf[x], val);
    }
    ll max_ele() {
        return *max_element(buf.begin(), buf.end());
    }
};
struct Task {
    int a, b;
    ll p;
};
void solve() {
    int n;
    cin >> n;
    set<int> pos;
    map<ll, int> vpos;
    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].a >> tasks[i].b >> tasks[i].p;
        pos.insert(tasks[i].a);
        pos.insert(tasks[i].b);
    }
    // map to smaller range
    auto it = pos.begin();
    for (int i = 1; i <= (int)pos.size(); i++) {
        vpos.emplace(*it, i);
        it++;
    }
    for (int i = 0; i < n; i++) {
        tasks[i].a = vpos[tasks[i].a];
        tasks[i].b = vpos[tasks[i].b];
    }
    auto comp = [](Task& lhs, Task& rhs) {
        if (lhs.b != rhs.b)
            return lhs.b < rhs.b;
        if (lhs.a != rhs.a)
            return lhs.a < rhs.a;
        return lhs.p < rhs.p;
    };
    sort(tasks.begin(), tasks.end(), comp);

    BIT bit;
    bit.init(2 * n + 1);
    for (int i = 0; i < n; i++) {
        bit.modify(tasks[i].b + 1, bit.query(tasks[i].a) + tasks[i].p);
    }
    cout << bit.max_ele() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
