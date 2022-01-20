#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 0x7FFFFFFF
using namespace std;
int W[105], V[105], dp[10005];
int main() {
	int T, N, M; 
	for(scanf("%d",&T); T ;T--){
		int ans = 0, val = 0;
		scanf("%d %d",&N,&M);
		for(int i = 1;i <= N;i++) {
			scanf("%d %d", &W[i], &V[i]);
			val+=V[i];
		}
		memset(dp, 0x7F, sizeof(dp));
		dp[0] = 0;
		for(int y = 1;y <= N;y++)for(int x = val;x >= V[y];x--){
			dp[x] = min(dp[x], dp[x - V[y]] + W[y]);
		}
		for(int i = val;i >=0;i--)if(dp[i]<=M){
			ans = i;
			break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

