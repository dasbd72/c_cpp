// 12602.c
#include <stdio.h>
#include <stdlib.h>
#define ll long long
ll len[52];
void OuQ(int K, ll L, ll R){
    if((L < 0 && R < 0) || (L >= len[K] && R >= len[K])) return;
    if(K == 0) return;

    if(L <= 0) putchar('O');
    OuQ(K-1, L-1, R-1);
    if(L <= 1 + len[K-1] && R >= 1 + len[K-1]) putchar('u');
    OuQ(K-1, L-len[K-1]-2, R-len[K-1]-2);
    if(R >= len[K]-1) putchar('Q');
}
int main(){
    int K;
    ll L, R;
    for(int i = 1; i <= 50; i++) len[i] = len[i-1]*2 + 3;
    while (scanf("%d %lld %lld", &K, &L, &R) != EOF){
        OuQ(K, L, R);
        puts("");
    }
}