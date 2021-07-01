#include<stdio.h>
#define ll long long
int N;
char s[105];
ll value(int);
int closepos(int);
int main()
{
    scanf("%d%s", &N, s+1);
    s[0]='(', s[N+1]=')';
    printf("%lld\n", value(0)/2);
    return 0;
}
//return the value of this parentheses
ll value(int start){
    //ending condition is the () which is 1
    if(s[start] == '(' && s[start+1] == ')') return 1;
    int end = closepos(start);
    ll sum = 0;
    for(int i = start+1; i < end; i++) {
        sum += value(i);
        i = closepos(i);
    }
    return sum*2;
}
//find the endpoint of this layer of parentheses
int closepos(int start){
    int layer = 0;
    for(int i = start; i <= N+1; i++){
        if(s[i] == '(') layer++;
        else if(s[i] == ')') layer--;
        if(layer == 0) return i;
    }
    return N-1;
}