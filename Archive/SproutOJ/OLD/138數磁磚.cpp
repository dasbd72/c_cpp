#include<stdio.h>
#include<math.h>
#define _MAX 1000007 
int T, N;
int dp[50007][2] = {};
int _color(int _n,int a){
	if(dp[_n][a]) return(dp[_n][a]);
	else if(a == 0){
		dp[_n][0] = (_color(_n-1, 0) + _color(_n-1, 1) )%_MAX;
		return dp[_n][0];
	}
	else if(a == 1){
		dp[_n][1] = ((_color(_n-1, 0) + _color(_n-1, 1)) * 2 + _color(_n-1, 1) )%_MAX;
		return dp[_n][1];
	}
}
int main(){
	dp[1][0] = 1, dp[1][1] = 2;
	for(int i=2;i<=100000;i+=2){
		_color( i/2, 0);
		_color( i/2, 1);
	}
	for(scanf("%d",&T);T;T--){
		scanf("%d",&N);
		if(N%2!=0){
			printf("0\n");
		}
		else printf("%d\n",(_color( N/2, 0) + _color( N/2, 1)) % 1000007);
	}
	return 0;
}
