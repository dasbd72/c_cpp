#include<stdio.h>
int rowInCol[10], N, ans;
void solve(int);
int main()
{
    scanf("%d", &N);
    solve(0);
    printf("%d", ans);
    return 0;
}
void solve(int col)
{
    if(col == N) ans ++;
    for(int row = 0, run; row < N; row++){
        run = 1;
        for(int c = 0; c < col; c++)
            if(rowInCol[c] == row || c + rowInCol[c] == col + row || c - rowInCol[c] == col - row)
                run = 0;
        if(!run) continue;
        rowInCol[col] = row;
        solve(col+1);
    }
}