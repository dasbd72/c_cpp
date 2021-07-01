#include<stdio.h>
int main()
{
    int row, col;
    short A[1005][1005];
    scanf("%d%d", &row, &col);
    for(int y = 0; y < row; y++) for(int x = 0; x < col; x++) scanf("%d", &A[y][x]);
    for(int y = 0; y < col; y++) for(int x = 0; x < row; x++) x == row-1 ? printf("%d\n", A[x][y]) : printf("%d ", A[x][y]);
    return 0;
}