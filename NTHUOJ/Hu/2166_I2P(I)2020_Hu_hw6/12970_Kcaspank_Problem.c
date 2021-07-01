/*
To every item, pick or not pick.
The max value of i and k can be written into sum[i][k]
which i stands for the index of picking, and k for the exact value of choosing
sum[i][k] = max{sum[i-1][k], sum[i-1][k-w[i]]+v[i]}
the sum means when the item i, and the total current weight is less than or equal k, pick or not pick i. 

And then you can compress the sum array into dp, because you only need to see the integer left & above this block 
*/
#include<stdio.h>
int main()
{
    int n, totw, w[30], v[30];
    long long dp[1005]={0}, ans = 0;
    scanf("%d%d", &n, &totw);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &w[i], &v[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = totw; j >= 0; j--) if(j - w[i] >= 0){
            dp[j] = dp[j-w[i]]+v[i] > dp[j] ? dp[j-w[i]]+v[i] : dp[j];
        }
    }
    for(int j = 1; j <= totw; j++) ans = dp[j] > ans ? dp[j] : ans;
    printf("%lld\n", ans);
}