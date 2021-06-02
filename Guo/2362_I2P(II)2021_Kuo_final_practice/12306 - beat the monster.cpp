#include <bits/stdc++.h>
using namespace std;
int main() {
    int L, HP, MHP, MDMG, Ans;
    vector<pair<int, int>> data;
    data.push_back(make_pair(0, 0));
    cin >> L >> HP >> MHP >> MDMG;
    for (int i = 0; i < L; i++) {
        int dmgi, hli;
        cin >> dmgi >> hli;
        data.push_back(make_pair(dmgi, hli));
    }
    /**
     * @brief BFS's que
     * @param HP
     * @param LV
     * @param MHP
     * @param steps
     */
    Ans = -1;
    queue<tuple<int, int, int, int>> tasks;
    tasks.push(make_tuple(HP, 1, MHP, 0));
    while (!tasks.empty()) {
        auto [hp, lv, mhp, steps] = tasks.front();
        tasks.pop();
        // cout << hp << " " << lv << " " << mhp;
        if (mhp <= 0) {
            Ans = steps;
            break;
        }
        if (hp <= 0) continue;

        tasks.push(make_tuple(hp - MDMG, lv, mhp - data[lv].first, steps + 1));
        tasks.push(make_tuple(hp - MDMG + data[lv].second, lv, mhp, steps + 1));
        if (lv < L)
            tasks.push(make_tuple(hp - MDMG, lv + 1, mhp, steps + 1));
    }
    cout << Ans << endl;
}