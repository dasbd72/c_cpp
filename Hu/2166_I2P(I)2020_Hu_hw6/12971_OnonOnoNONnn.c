#include<stdio.h>
int n, m;
int s[22][22]={0}; // start from 1 to n or i to m cuz easier to do switching
int dy[]={0, -1, 0, 1, 0}, dx[]={0, 0, 1, 0, -1}; // the directions to switch the bulbs
int ans = (int)1e9; // initialize with maximum number

int check();
void solve(int, int, int);
void turn(int, int);

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &s[i][j]);
    solve(1,1,0);
    if(ans != 1e9) printf("%d\n", ans);
    else printf("no solution\n");
}
// recursion in to every posibility
void solve(int y, int x, int cnt)
{
    if(y == n+1 && x == 1){
        if(check()) ans = cnt < ans ? cnt : ans;
        return;
    }
    for(int i = 0; i < 2; i++){
        if(i) turn(y, x);

        if(x == m) solve(y+1, 1, cnt+i);
        else solve(y, x+1, cnt+i);

        if(i) turn(y, x);
    }
    return;
}
//check if the current is correct
int check()
{
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if(s[i][j] == 0) return 0;
    return 1;
}
// switch the bulbs
void turn(int y, int x)
{
    for(int i = 0; i < 5; i++)
        s[y + dy[i]][x + dx[i]] = (s[y + dy[i]][x + dx[i]] + 1)  % 2;
    return;
}
