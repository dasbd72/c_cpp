// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
void solve(int grid[5][5], vector<int>& vec, int& dst, vector<int>& ansvec) {
    if (vec.size() == 5) {
        int curdst = 0;
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                int mindst = 0x7fffffff;
                for(int i = 0; i < 5; i++) {
                    int ri = vec[i] / 5;
                    int ci = vec[i] % 5;
                    mindst = min(mindst, (abs(ri - r) + abs(ci - c)) * grid[r][c]);
                }
                curdst += mindst;
            }
        }
        if(curdst < dst) {
            ansvec = vec;
            dst = curdst;
        }
        return;
    }
    int start = 0;
    if (vec.size() != 0)
        start = *vec.rbegin() + 1;
    for (int i = start; i < 25; i++) {
        vec.push_back(i);
        solve(grid, vec, dst, ansvec);
        vec.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int grid[5][5] = {};
        cin >> n;
        for (int i = 0; i < n; i++) {
            int r, c, p;
            cin >> r >> c >> p;
            grid[r][c] = p;
        }
        vector<int> vec;
        int dst = 0x7fffffff;
        vector<int> ansvec;
        solve(grid, vec, dst, ansvec);
        for (int i = 0; i < 5; i++) {
            cout << ansvec[i] << (i == 4 ? "\n" : " ");
        }
    }

    return 0;
}