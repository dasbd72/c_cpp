#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    stack<int> tmp, stationA;
    queue<int> stationB;
    cin >> T;
    while (T--) {
        stationB = queue<int>();
        tmp = stationA = stack<int>();
        cin >> N;
        for (int i = N, inp; i >= 1; i--) {
            cin >> inp;
            stationB.push(inp);
            stationA.push(i);
        }
        while (!stationB.empty()) {
            if (!tmp.empty() && tmp.top() == stationB.front()) {
                tmp.pop();
                stationB.pop();
            } else if (!stationA.empty() && stationA.top() == stationB.front()) {
                stationA.pop();
                stationB.pop();
            } else if (!stationA.empty()) {
                tmp.push(stationA.top());
                stationA.pop();
            } else {
                break;
            }
        }
        cout << (stationB.empty() ? "Yes" : "No") << "\n";
    }

    return 0;
}