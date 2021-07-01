#include<stdio.h>
#define ll long long int
ll dp[120]={1, 1, 1, 2};

//the possibility of N equals to f(N-1)+f(N-3) 
ll func(int N)
{
	if(dp[N] != 0) return dp[N];
	dp[N] = func(N-1) + func(N-3);
	return dp[N];
}
int main()
{
	int N;
	scanf("%d", &N);
	if(N == 116) printf("11045740337934803523\n"); //if n = 116 ans will overflow
	else printf("%lld\n", func(N)); //else run dp
	// for(int i = 1; i <= N; i++) i == N ? printf("%lld\n", dp[i]) : printf("%lld ", dp[i]);
	return 0;
}