#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef pair<int,int> tp;
int main(){
	int T; cin >> T;
	while(T--){
		int N, K, C, val[100005]={};
		cin >> N >> K >> C;
		for(int i = 0; i < N; i++) cin >> val[i];
		
		int dp[2][100005]={{},{val[0]}};
		priority_queue<tp,vector<tp>,less<tp> > que;
		for(int i = 1; i < N; i++){
			while(!que.empty() && i-que.top().second > K) que.pop();
			que.push(make_pair(dp[1][i-1] + (i-1)*C, i-1));
			dp[0][i] = fmax(dp[0][i-1], dp[1][i-1]);
			dp[1][i] = fmax(val[i], val[i] - i*C + que.top().first);
			
		}
		cout << fmax(dp[0][N-1], dp[1][N-1]) << '\n';
	}
	return 0;
}
/*
2
4 2 1
-1 3 -2 4
4 2 2
-1 3 -2 4
*/
