#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	const int M = 510509;
	int N, Q, H[150005]={};
	cin >> N >> Q;
	for(int i=0;i<N;i++)cin>>H[i+1];
	while(Q--){
		int l, r, x, y, ans = 0;
		cin >> l >> r >> x >> y;
		long long tx = x;
		for(int i = 1; i <= 2; i++)tx = (tx*x) % M;
		for(int i = l; i <= r; i++){
			long long c = tx, dh = (H[i]*H[i])%M;
			c = (c+H[i]*x)%M;
			c = (c+dh)%M;
			if(c == y) ans++;
		}
		cout << ans << '\n';
	}
}

