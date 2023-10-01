#include <bits/stdc++.h>
using namespace std;

int low_bit_log(int x) {
    switch (x) {
        case 1:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 8:
            return 3;
        case 16:
            return 4;
        case 32:
            return 5;
        case 64:
            return 6;
        case 128:
            return 7;
        case 256:
            return 8;
        case 512:
            return 9;
        default:
            return -1;
    }
}
int low_bit(int x) {
    return low_bit_log(x & -x);
}
int get_block(int idx) {
    int r = idx / 9;
    int c = idx % 9;
    int i = r / 3;
    int j = c / 3;
    return i * 3 + j;
}
bool recursive(string& sudoku, int idx, array<int, 9>& blocks, array<int, 9>& rows, array<int, 9>& cols) {
    if (idx == 81) {
        return true;
    }

    int ava = ~(blocks[get_block(idx)] | rows[idx / 9] | cols[idx % 9]) & 0b1111111110;
    if (sudoku[idx] == '.') {
        while (ava) {
            int num = low_bit(ava);
            ava &= ~(1 << num);
            blocks[get_block(idx)] |= (1 << num);
            rows[idx / 9] |= (1 << num);
            cols[idx % 9] |= (1 << num);
            sudoku[idx] = num + '0';
            if (recursive(sudoku, idx + 1, blocks, rows, cols))
                return true;
            blocks[get_block(idx)] &= ~(1 << num);
            rows[idx / 9] &= ~(1 << num);
            cols[idx % 9] &= ~(1 << num);
            sudoku[idx] = '.';
        }
    } else {
        int num = sudoku[idx] - '0';
        if (1 & (ava >> num)) {
            blocks[get_block(idx)] |= (1 << num);
            rows[idx / 9] |= (1 << num);
            cols[idx % 9] |= (1 << num);
            if (recursive(sudoku, idx + 1, blocks, rows, cols))
                return true;
            blocks[get_block(idx)] &= ~(1 << num);
            rows[idx / 9] &= ~(1 << num);
            cols[idx % 9] &= ~(1 << num);
        }
    }
    return false;
}
bool solve(string& sudoku) {
    array<int, 9> blocks;
    array<int, 9> rows;
    array<int, 9> cols;
    fill(blocks.begin(), blocks.end(), 0);
    fill(rows.begin(), rows.end(), 0);
    fill(cols.begin(), cols.end(), 0);
    return recursive(sudoku, 0, blocks, rows, cols);
}
void solve() {
    string sudoku;
    while (cin >> sudoku) {
        if (sudoku == "end")
            break;
        if (solve(sudoku))
            cout << sudoku << "\n";
        else
            cout << "No solution.\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}