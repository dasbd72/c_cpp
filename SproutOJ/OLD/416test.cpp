#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 1000000007
using namespace std;
int TN, NF, PF, _K;
int main() {
	scanf("%d %d %d %d",&TN,&NF,&PF,&_K);
	if(NF>PF){
		NF-=PF;
		TN-=PF;
	}else{
		NF=PF-NF;
		TN=PF-1;
	}
	
	long long dp[2][TN+1], ans = 0;
	memset(dp,0,sizeof(dp));
	
	dp[0][NF]=1;
	for(int k = 1;k <= _K;k++){
		//cout << k << "-------" << endl;
		for(int h = 2;h <= TN;h++)for(int l = 1;l < h;l++){
			dp[k%2][h-l] += dp[(k+1)%2][h];
			dp[k%2][h-l] %= MAXN;
			//if(dp[(k+1)%2][h])printf("%d to %d\n",h,h-l);
			if(h+l<=TN){
				dp[k%2][h+l] += dp[(k+1)%2][h];
				dp[k%2][h-l] %= MAXN;
				//if(dp[(k+1)%2][h])printf("%d to %d\n",h,h+l);
			}
		}
		memset(dp[(k+1)%2],0,sizeof(dp[(k+1)%2]));
	}
	for(int f = 1;f <= TN;f++){
		ans+=dp[_K%2][f];
		ans %= MAXN;
	}
	printf("%lld\n",ans);
	return 0;
}
