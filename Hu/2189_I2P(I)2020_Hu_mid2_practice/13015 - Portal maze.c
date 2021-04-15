#include<stdio.h>
#define MAXN 302

int T, N, M;
char maze[MAXN][MAXN];
int been[MAXN][MAXN];
int Y[]={-1, 0, 1, 0}, X[]={0, 1, 0, -1};
int startP[2], portP[26][2], endP[2];

void sol(int,int);
int main(){
    for(scanf("%d", &T); T--; ){
        //initialize
        for(int y = 0; y < MAXN; y++) for(int x = 0; x < MAXN; x++) maze[y][x] = been[y][x] = 0;
        //input
        scanf("%d%d", &N, &M);
        for(int y = 1; y <= N; y++) scanf("%s", maze[y]+1);
        //save position
        for(int y = 1; y <= N; y++) for(int x = 1; x <= M; x++){
            char c = maze[y][x];
            if(c == '$') startP[0] = y, startP[1] = x;
            else if(c == '&') endP[0] = y, endP[1] = x;
            else if(c >= 'A' && c <= 'Z') portP[c-'A'][0] = y, portP[c-'A'][1] = x;
        }
        sol(startP[0], startP[1]);
        if(been[endP[0]][endP[1]]) printf("Yes\n");
        else printf("No\n");
    }
}
void sol(int y, int x){
    been[y][x] = 1; // save if you can arrive
    if(maze[y][x] >= 'a' && maze[y][x] <= 'z') sol(portP[maze[y][x]-'a'][0], portP[maze[y][x]-'a'][1]); //teleport
    else for(int d = 0; d < 4; d++){ //spread 4 directions
        int dy = y+Y[d], dx = x+X[d];
        if(maze[dy][dx] && maze[dy][dx]!='#' && !been[dy][dx])
            sol(dy,dx);
    }
}