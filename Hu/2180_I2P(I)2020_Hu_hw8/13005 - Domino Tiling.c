#include<stdio.h>
// split the possibility into two cases : 
// 3 * 2 -> 3 kinds
// 3 * 2k, k > 1 -> each 2 kinds
int save[22]={};
int ans(int M){
    if(M == 0) return 1;
    if(!save[M]){
        save[M] += ans(M-1) * 3;
        for(int i = 2; i <= M; i++) save[M] += ans(M-i) * 2;
    }
    return save[M];
}
int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", ans(N/2));
}