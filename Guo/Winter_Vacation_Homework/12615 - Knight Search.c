// 12615.c
#include <stdio.h>
#include <string.h>
const int Y[]={-2,-2,-1,1,2,2,1,-1}, X[]={-1,1,2,2,1,-1,-2,-2};
const char S[]="ICPCASIASG";
int N, availible;
char board[105][105];
void run(int y, int x, int pos){
    if(pos == 10) availible = 1;
    if(availible) return;
    for(int i = 0; i < 8; i++){
        int _y = y + Y[i], _x = x + X[i];
        if(_y >= 0 && _y < N && _x >= 0 && _x < N && board[_y][_x] == S[pos])
            run(_y, _x, pos+1);
    }
}
int main(){
    scanf("%d", &N);
    for(int r = 0; r < N; r++) for(int c = 0; c < N; c++) scanf("%1s", &board[r][c]);
    for(int r = 0; r < N; r++) for(int c = 0; c < N; c++) if(board[r][c] == 'I') run(r, c, 1);
    if(availible) puts("YES");
    else puts("NO");
}