#include<stdio.h>
#define MAXN 22
int n, totw, w[MAXN], v[MAXN];
int q, a, b;
long long ans[MAXN][MAXN]; // the most important part is to save the answers when (a, b) must be chosen

//hand made max funtion
long long max(long long num1, long long num2){
    return num1 > num2 ? num1 : num2;
}

//recursion that will return the value
long long pick(int idx, long long currw){
    //the current value u have is the combination of idx-1
    if(currw > totw) return -1e18; // return a very small number if the 1 ~ idx-1 combinations is unavalible
    if(idx == n+1) return 0; // else if idx == n+1, its an availible combination
    if(idx == a || idx == b) return pick(idx+1, currw+w[idx] ) + v[idx]; // else if a and b must be chosen
    return max( pick(idx+1, currw), pick(idx+1, currw+w[idx]) + v[idx] ); // chose the combination with the maximum value
}
int main()
{
    scanf("%d%d", &n, &totw);
    for(int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) ans[i][j] = -1;
    for(scanf("%d", &q); q--; ){
        scanf("%d%d", &a, &b);
        if(ans[a][b] == -1) ans[a][b] = pick(1, 0);
        if(ans[a][b] < -1) printf("0\n");
        else printf("%lld\n", ans[a][b]);
    }
    return 0;
}