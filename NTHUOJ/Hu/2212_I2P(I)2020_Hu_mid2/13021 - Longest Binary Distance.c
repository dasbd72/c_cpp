#include<stdio.h>
int Q, lastpos, dist;
unsigned long long N;
int main(){
    for(scanf("%d", &Q); Q--;){
        scanf("%llu", &N);
        lastpos = -1, dist = -1;
        for(int i = 0; N ; i++){
            if(N & 1){
                if(lastpos == -1) lastpos = i;
                else{
                    dist = i-lastpos-1 > dist ? i-lastpos-1 : dist;
                    lastpos = i;
                }
            }
            N >>= 1;
        }
        printf("%d\n", dist);
    }
}