// 12603.c
#include<stdio.h>
#include<stdlib.h>
int main(){
    int N, prev, curr, time;
    char S[200005];
    int mintime = 0x7FFFFFFF;
    scanf("%d %s", &N, S);
    for(int i = 0; i < N; i++){
        prev = curr;
        scanf("%d", &curr);
        if(i == 0) continue;

        time = (curr-prev)/2;
        if(S[i] == 'L' && S[i-1] == 'R' && time < mintime) mintime = time; 
    }
    if(mintime == 0x7FFFFFFF) puts("-1");
    else printf("%d\n", mintime);
}