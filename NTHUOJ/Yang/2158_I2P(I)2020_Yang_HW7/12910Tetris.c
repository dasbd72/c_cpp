#include <stdio.h>
int N, M;
char tet[42][42] = {0};

int drop();
void clear();

int main() {
    scanf("%d%d", &N, &M);
    for (int row = 0; row < N; row++) scanf("%s", tet[row]);

    while (drop())
        ;
    clear();

    for (int row = 0; row < N; row++) printf("%s\n", tet[row]);
}
void clear() {
    //turn into 'x'
    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++)
            if (tet[row][col] == 'o')
                tet[row][col] = 'x';
    //scan from bottom, if this row is full, clear all and move all the tetris on top down a block
    for (int row = N - 1; row >= 0; row--)
        for (int col = 0; col < M; col++) {
            if (tet[row][col] == '.')
                break;
            if (col == M - 1) {
                for (int i = row; i > 0; i--)
                    for (int j = 0; j < M; j++) tet[i][j] = tet[i - 1][j];
                for (int j = 0; j < M; j++) tet[0][j] = '.';
                row++;
            }
        }
}
int drop() {
    //if any 'o' is just above the boarder or 'x', return 0, which stands for can't drop no more
    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++)
            if (tet[row][col] == 'o')
                if (row == N - 1 || tet[row + 1][col] == 'x')
                    return 0;
    //drop the 'o's
    for (int row = N - 1; row >= 0; row--)
        for (int col = 0; col < M; col++)
            if (tet[row][col] == 'o')
                tet[row][col] = '.', tet[row + 1][col] = 'o';
    return 1;
}