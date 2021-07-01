#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAXN 10
int map[MAXN][MAXN];
int dp[2][MAXN];
int M,N;
int f(int y,int x){
	if(y==0&&x==0)return map[y][x];
	for(int i=0;i<N;i++)dp[(y+1)%2][i]=map[y][i];
	dp[y%2][x]=max(dp[(y+1)%2][i],dp[y%2][i])+map[y][x];
	
}
int main(){
	scanf("%d%d",&M,&N);
	for(int y=0;y<M;y++)for(int x=0;x<N;x++){
		scanf("%d",&map[y][x]);
	}
	for(int i=0;i<N;i++)dp[1][i]=map[M-1][y];
	printf("%d\n",dp(M-1,N-1));
}
