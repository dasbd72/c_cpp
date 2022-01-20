#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	int T, N, M, K;
	for(scanf("%d",&T);T;T--){
		int W[105], V[105], tot = 0, ans = 0;
		int dp[1005][105]={};
		
		scanf("%d %d %d",&N, &M ,&K); //num satisfy maxeat
		
		for(int i = 1;i <= N;i++){
			scanf("%d%d",&W[i] ,&V[i]);	
		}
		memset(dp,-0x7F,sizeof(dp));
		dp[0][0]=0;
		
		for(int y = 1;y <= N;y++)for(int x = M;x >= W[y];x--)for(int u = 1;u <= K;u++){
			dp[x][u] = fmax(dp[x][u], dp[x-W[y]][u - 1] + V[y]);
		}
		for(int i=1;i<=M;i++)for(int j=1;j<=K;j++)ans=fmax(ans,dp[i][j]);
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
3 6 3
2 4
3 5
4 6
3 9 2
2 4
3 5
4 6
*/
