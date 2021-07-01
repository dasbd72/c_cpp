#include<stdio.h>
#define MOD 10007
int combi[500][500]={};

int gen(int n, int k)
{
	int ans;
	if(combi[n][k]) return combi[n][k];
	if(k == 0 || n == k) ans = 1;
	else ans = gen(n-1, k) + gen(n-1, k-1);
	ans %= MOD;
	combi[n][k] = ans;
	return ans;
}
int main()
{
	int N, x[100005]={}, y[100005]={};
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d",&x[i]);
	for(int i = 0; i < N; i++) scanf("%d",&y[i]);
	int ans = 1; 
	for(int i = 0; i < N; i++)
	{
		ans = (ans * gen(x[i], y[i])) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}