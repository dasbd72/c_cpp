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
	
	unsigned long long dp[2][TN+1], tot[2]={1,0},ans = 0;
	memset(dp,0,sizeof(dp));
	dp[0][NF]=1;
	
	for(int k = 1;k <= _K;k++){
		for(int h = 1;h <= TN;h++){
			if(h%2 == 0)tot[(k+1)%2]-=dp[(k+1)%2][h/2];
			dp[k%2][h]+=(tot[(k+1)%2]-dp[(k+1)%2][h]);
			dp[k%2][h]%=MAXN;
			tot[k%2]+=dp[k%2][h];
		}
		memset(dp[(k+1)%2],0,sizeof(dp[(k+1)%2]));
		tot[(k+1)%2] = 0;
	}
	cout << tot[_K%2]%MAXN << endl;
	return 0;
}
/*
8 2 5 2 ->
7 1 2 2
140 112 31 201
*/
