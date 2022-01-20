#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 0x7FFFFFFF
int ST[105], SV[105];
int dp[1000005];
int Eat(int n,int w){
	if(w-ST[n]<=0)return dp[w];
	else dp[w] = fmax(dp[w], dp[w-ST[n]] + SV[n]);
}
int main(){
	int T, N, M; 
	for(scanf("%d",&T); T ;T--){
		int ans = 0;
		scanf("%d %d",&N,&M);
		for(int i = 1;i <= N;i++) scanf("%d %d", &ST[i], &SV[i]);
		for(int i = 1;i <= M;i++) dp[i] = (ST[1] <= i) ? SV[1] : 0;
		for(int y = 2;y <= N;y++)for(int x = M;x >= 1;x--){
			Eat(y, x);
		}
		for(int i = 1;i <= M;i++) ans = fmax(dp[i], ans);
		printf("%d\n", ans);
	}
}
