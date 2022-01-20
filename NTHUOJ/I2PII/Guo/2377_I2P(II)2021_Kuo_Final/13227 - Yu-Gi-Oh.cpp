#include <bits/stdc++.h>
using namespace std;
using PLL = pair<long long, long long>;

struct comparitor {
    bool operator()(PLL& pa, PLL& pb) {
        if (pa.first < pb.first) return true;
        if (pa.first > pb.first) return false;
        if (pa.second < pb.second) return true;
        return false;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, a;
    cin >> N;
    set<PLL, greater<PLL>> myset;
    map<long long, long long> findcntof;
    while (N--) {
        cin >> a;
        long long cnt = findcntof[a]++;
        PLL cur_pair = make_pair(cnt, a);
        myset.erase(cur_pair);
        cur_pair.first++;
        myset.insert(cur_pair);

        cout << (*myset.begin()).second << "\n";
    }
}