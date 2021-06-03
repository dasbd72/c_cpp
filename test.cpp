#include <bits/stdc++.h>
using namespace std;
int main() {
    map<pair<int, int>, int> mp;
    mp[make_pair(10, 5)] = 10;
    mp[make_pair(10, 5)] = 1;
    mp[make_pair(8, 5)] = 1000;
    for (auto item : mp) {
        cout << item.first.first << " " << item.first.second << " " << item.second << endl;
    }
}
