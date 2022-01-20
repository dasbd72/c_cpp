#include<stdio.h>
int N, R, C;
char maze[105][105];
int dR[4] = {-1, 0, 1, 0}, dC[4] = {0, 1, 0, -1};
int Spos[2], used[105][105];
int pathCnt, leaststep;
void solve(int, int, int);
int main()
{
    for(scanf("%d", &N); N--; ){
        //Input
        scanf("%d%d", &R, &C);
        for(int r = 1; r <= R; r++){
            scanf("%s", maze[r]+1);
            for(int c = 1; c <= C; c++) if(maze[r][c] == 'S') Spos[0] = r, Spos[1] = c;
        }
        //reset variables
        pathCnt = 0, leaststep = 1e9;
        solve(Spos[0], Spos[1], 0);
        if(pathCnt) printf("%d %d\n", pathCnt, leaststep);
        else printf("0 -1\n");
    }
}
void solve(int pR, int pC, int step){
    if(maze[pR][pC] == 'F'){
        pathCnt++;
        leaststep = step < leaststep ? step : leaststep;
        return;
    }
    // run 4 directions and record that you've been there
    for(int d = 0; d < 4; d ++) 
        if((maze[pR+dR[d]][pC+dC[d]] == '$' || maze[pR+dR[d]][pC+dC[d]] == 'F') && !used[pR+dR[d]][pC+dC[d]]){
            used[pR+dR[d]][pC+dC[d]] = 1;
            solve(pR+dR[d], pC+dC[d], step+1);
            used[pR+dR[d]][pC+dC[d]] = 0;
        }
}