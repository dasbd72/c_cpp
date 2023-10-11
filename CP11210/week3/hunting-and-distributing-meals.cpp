#include <bits/stdc++.h>
using namespace std;

int order(string position) {
    if (position == "elder")
        return 1;
    else if (position == "nursy")
        return 2;
    else if (position == "kit")
        return 3;
    else if (position == "warrior")
        return 4;
    else if (position == "appentice")
        return 5;
    else if (position == "medicent")
        return 6;
    else if (position == "deputy")
        return 7;
    else if (position == "leader")
        return 8;
    return 9;
}
void solve() {
    int N, M;
    while (cin >> N >> M) {
        vector<string> name_list;
        vector<tuple<int, long long, string, int> > compare_list;
        for (int i = 0; i < N; i++) {
            string name, position;
            long long age;
            cin >> name >> position >> age;
            name_list.emplace_back(name);
            string lower_name = name;
            for (auto &c : lower_name)
                c = tolower(c);
            if (position == "appentice")
                compare_list.emplace_back(order(position), age, lower_name, i);
            else
                compare_list.emplace_back(order(position), -age, lower_name, i);
        }
        sort(compare_list.begin(), compare_list.end());
        for (int i = 0; i < M && i < N; i++) {
            cout << name_list[get<3>(compare_list[i])] << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
