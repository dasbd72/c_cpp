#include<stdio.h>
int N, h[25];
int minjump = 1e9, mincost = 1e9;
int abs(int x, int y){ // hand made absolute function
    return x > y ? x - y : y - x;
}
void solve(int idx, int jump, int cost){
    if(idx == N-1){
        if(cost < mincost) mincost = cost, minjump = jump;
        else if(cost == mincost) minjump = jump < minjump ? jump : minjump;
        return;
    }
    solve(idx+1, jump+1, cost + abs(h[idx], h[idx+1]));
    if(idx + 2 <= N-1) solve(idx+2, jump+1, cost + abs(h[idx], h[idx+2]));
}
int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &h[i]);
    solve(0, 0, 0);
    printf("%d %d\n", mincost, minjump);
}