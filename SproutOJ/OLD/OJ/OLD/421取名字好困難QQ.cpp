#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;while(T--){
		int a[100005], dp[100005], length = 0;
		cin >> N >> M;
		for(int i = 1;i <= N;i++){ cin >> a[i]; }
		dp[0] = -0x7FFFFFFF;
		for(int i = 1;i <= N;i++)dp[i] = 0x7FFFFFFF;
		for(int i = 1;i <= N;i++){
			for(int l = 1;dp[l-1] <= a[i]*2&&l<=i;l++){
				if(a[i] >= M && dp[l-1] <= a[i]){
					dp[l] = fmin(dp[l], a[i]);
					length = max(l,length);
				}
				else if(a[i] * 2 >= M){
					dp[l] = fmin(dp[l], a[i] * 2);
					length = max(l,length);
				}
			}
		}
		cout << length << endl;
	}
	return 0;
}

