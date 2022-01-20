#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	int T; cin >> T;
	while(T--){
		int N, K, C, val[100005];
		int dp[2][100005]={};
		cin >> N >> K >> C;
		for(int i=0; i<N; i++) cin >> val[i];
		dp[1][0]=val[0];
		for(int i=1; i<N; i++){
			int tmp=-200000;
			for(int j=i-1; i-j<=K; j--){
				
			}
		}
	}
	return 0;
}

