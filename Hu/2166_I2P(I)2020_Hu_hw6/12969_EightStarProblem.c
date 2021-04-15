#include<stdio.h>
int n, board[10][10];
long long ans = -1e18;
int posrow[10];
void solve(int, long long);
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &board[i][j]);
    solve(0, 0);
    if(ans == -1e18) printf("no solution\n");
    else printf("%lld\n", ans);
}
void solve(int idx, long long cost)
{
    if(idx == n){
        ans = cost > ans ? cost : ans;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        int canUse = 1;
        for(int j = 0; j < idx; j++){
            if(posrow[j] == i || j + posrow[j] == idx + i || j - posrow[j] == idx - i) canUse = 0;
        }
        if(canUse){
            posrow[idx] = i;
            solve(idx+1, cost+board[i][idx]);
        }
    }
    return;
}