#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
int T,N,a[100007]={};
int M[100007][3]={},tmp;//0n 1nn 2y
int dp(int n,int inc){
	if(n==1||n==2||M[n][inc]!=0)return(M[n][inc]);
	if(inc==0){
		M[n][inc]=dp(n-1,2);
		return M[n][inc];
	}
	if(inc==1){
		M[n][inc]=dp(n-1,0);
		return M[n][inc];
	}
	if(inc==2){
		M[n][inc]=fmax(dp(n-1,0),dp(n-1,1))+a[n];
		return M[n][inc];
	}
}
int main(){
	for(scanf("%d",&T);T;T--){
		memset(a,0,sizeof(a));
		memset(M,0,sizeof(M));
		
		scanf("%d",&N);
		for(int iN=1;iN<=N;iN++){
			scanf("%d",&a[iN]);
		}
		M[1][2]=a[1];
		M[2][0]=a[1],M[2][2]=fmax(a[1],a[2]);
		dp(N,1);
		int ans=fmax(dp(N,0),dp(N,2));
		printf("%d\n",ans);
	}
}
