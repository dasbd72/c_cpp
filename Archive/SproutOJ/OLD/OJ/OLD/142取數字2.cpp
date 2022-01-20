#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
int T, N, K, a[1005] = {};
int M[1005][2] = {}, tmp;//0n 1y
int dp(int x,int y){
	if(M[x][y] != 0)return M[x][y];
	if(x <= K && y == 1){
		M[x][y] = a[x];
		return a[x];
	}
	if(x <= K && y == 0){
		tmp = 0;
		for(int i=1;i<x;i++)tmp=a[i]>tmp?a[i]:tmp;
		M[x][y] = tmp;
		return tmp;
	}
	if(y == 1){
		M[x][y] = fmax(dp(x-K,0),dp(x-K,1)) + a[x];
		return M[x][y];
	}
	else{
		M[x][y] = fmax(dp(x-1,0),dp(x-1,1));
		return M[x][y];
	}
}
int main(){
	for(scanf("%d",&T);T;T--){
		memset(M, 0, sizeof(M));
		scanf("%d %d",&N,&K);
		for(int iN = 1;iN <= N;iN++){
			scanf("%d",&a[iN]);
		}
		int i0=dp(N,0),i1=dp(N,1),ans;
		ans=i0>i1?i0:i1;
		printf("%d\n",ans);
	}
}
