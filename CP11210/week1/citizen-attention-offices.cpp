#include <bits/stdc++.h>
using namespace std;
int get_distance(array<array<int, 5>, 5>& grid, array<int, 6>& choice) {
    int distance = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int part_distance = INT32_MAX;
            for (int i = 1; i <= 5; i++) {
                part_distance = min(part_distance, grid[r][c] * (abs(choice[i] / 5 - r) + abs(choice[i] % 5 - c)));
            }
            distance += part_distance;
        }
    }
    return distance;
}
void recursive(int idx, array<array<int, 5>, 5>& grid, int& best_distance, array<int, 6>& best_choice, int& curr_distance, array<int, 6>& curr_choice) {
    if (idx >= 6) {
        curr_distance = get_distance(grid, curr_choice);
        if (curr_distance < best_distance) {
            best_distance = curr_distance;
            best_choice = curr_choice;
        }
        return;
    }
    for (int i = curr_choice[idx - 1] + 1; i < 25; i++) {
        curr_choice[idx] = i;
        recursive(idx + 1, grid, best_distance, best_choice, curr_distance, curr_choice);
    }
}
void recursive_warpper(array<array<int, 5>, 5>& grid, array<int, 6>& best_choice) {
    array<int, 6> curr_choice;
    curr_choice[0] = -1;
    int best_distance = INT32_MAX, curr_distance = 0;
    recursive(1, grid, best_distance, best_choice, curr_distance, curr_choice);
}
void test_case() {
    int n;
    cin >> n;
    array<array<int, 5>, 5> grid;
    for (int i = 0; i < 25; i++) {
        grid[i / 5][i % 5] = 0;
    }
    while (n--) {
        int r, c, x;
        cin >> r >> c >> x;
        grid[r][c] = x;
    }

    array<int, 6> choice;
    recursive_warpper(grid, choice);
    for (int i = 1; i <= 5; i++) {
        cout << choice[i] << " ";
    }
    cout << "\n";
}
void solve() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}