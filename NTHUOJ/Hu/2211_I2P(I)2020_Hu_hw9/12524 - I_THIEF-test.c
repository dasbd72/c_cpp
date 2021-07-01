#include<stdio.h>
#define max(a,b) a>b?a:b
int N, S[105], dp[105], pick[105][105];
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", S+i);
    dp[1] = S[1], pick[1][1] = 1;
    for(int i = 2; i <= N; i++){
        if(dp[i-1] > dp[i-2]+S[i]){
            dp[i] = dp[i-1];
            for(int j = 1; j < i; j++) pick[i][j] = pick[i-1][j];
        }
        else{
            dp[i] = dp[i-2]+S[i];
            for(int j = 1; j < i-1; j++) pick[i][j] = pick[i-2][j];
            pick[i][i] = 1;
        }
    }
    for(int j = 1; j <= N; j++) if(pick[N][j]) printf("%d ", j);
}