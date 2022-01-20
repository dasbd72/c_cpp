#include <stdio.h>
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int T, N, M, cantp;
char ma[1005][1005], re[1005][1005];
void go(int y, int x) {
    re[y][x] = 1;
    for (int d = 0; d < 4; d++) {
        int _y = y + dy[d], _x = x + dx[d];
        if ((ma[_y][_x] == '*' || ma[_y][_x] == 'T') && !re[_y][_x])
            go(_y, _x);
    }
    if (ma[y][x] == 'T')
        cantp = 1;
}
int main() {
    for (scanf("%d", &T); T--;) {
        scanf("%d%d", &N, &M);
        cantp = 0;
        for (int i = 0; i <= N + 1; i++)
            for (int j = 0; j <= M + 1; j++)
                ma[i][j] = re[i][j] = 0;
        for (int i = 1; i <= N; i++)
            scanf("%s", ma[i] + 1);
        go(1, 1);
        if (cantp)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= M; j++)
                    if (ma[i][j] == 'T')
                        go(i, j);
        printf("%s\n", re[N][M] ? "Yes" : "No");
    }
}