#include<stdio.h>
int N;
char P[105]={};
int endpos(int);
long long solve(int);
int main()
{
    scanf("%d%s", &N, P+1);
    P[0] = '(', P[N+1] = ')', N+=2;
    printf("%lld\n", solve(0)/2);
    return 0;
}
int endpos(int pos){
    int cnt = 0;
    while(pos < N){
        if(P[pos] == '(') cnt ++;
        else cnt--;
        if(cnt == 0) return pos;
        pos++;
    }
}
long long solve(int pos){
    int end = endpos(pos);
    long long sum = 0;
    if(end == pos+1) return 1;
    for(int i = pos+1; i < end; i++){
        sum += solve(i);
        i = endpos(i);
    }
    return sum*2;
}