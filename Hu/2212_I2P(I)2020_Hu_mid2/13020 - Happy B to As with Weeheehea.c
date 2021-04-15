#include<stdio.h>
#define SWAP(a,b) {int __tmp__ = a;a=b;b=__tmp__;}
int N, K;
char A[100005][5][5];
int Y[]={-1,0,1,0}, X[]={0,1,0,-1};
int save[(1<<9)][11], tmpy, tmpx, ans;
int mapxpos(int n){
    int idx = 0;
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++){
        if(A[n][i][j] == 'x') return idx;
        idx++;
    }
}
int maptoint(int n){
    int sum = 0;
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) {
        sum <<= 1;
        if(A[n][i][j] == '1' || A[n][i][j] == 'x') sum++;
    }
    return sum;
}
void run(int y, int x, int k){
    save[maptoint(N)][mapxpos(N)] = 1;
    if(k == K) return;
    for(int d = 0; d < 4; d++){
        int dy = y + Y[d], dx = x + X[d];
        if(A[N][dy][dx]) {
            SWAP(A[N][y][x], A[N][dy][dx]);
            run(dy, dx, k+1);
            SWAP(A[N][y][x], A[N][dy][dx]);
        }
    }
}
int main(){
    scanf("%d %d", &N, &K);
    for(int n = 0; n <= N; n++) for(int i = 1; i <= 3; i++) 
        scanf("%s", A[n][i]+1); 
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) 
        if(A[N][i][j] == 'x') tmpy = i, tmpx = j;
    run(tmpy, tmpx, 0);
    for(int n = 0; n < N; n++) if(save[maptoint(n)][mapxpos(n)]) ans++;
    printf("%d\n", ans);
    return 0;
}