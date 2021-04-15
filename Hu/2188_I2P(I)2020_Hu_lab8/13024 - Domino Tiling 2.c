#include<stdio.h>
int N, M;
int board[55][55]={}, ans = 0;
int check(){
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(!board[i][j]) return 0;
    return 1;
}
void solve(int y, int x){
    if(y == N){
        if(check()) ans++;
    }
    else if(x == M) solve(y+1, 0);
    else if(board[y][x]) solve(y, x+1);
    else{
        if(!board[y][x+1] && x+1 != M){
            board[y][x] = board[y][x+1] = 1;
            solve(y,x+1);
            board[y][x] = board[y][x+1] = 0;
        }
        if(!board[y+1][x] && y+1 != N){
            board[y][x] = board[y+1][x] = 1;
            solve(y,x+1);
            board[y][x] = board[y+1][x] = 0;
        }
    }
}
int main()
{
    scanf("%d%d", &N, &M);
    solve(0,0);
    printf("%d\n", ans);
    return 0;
}