#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pt;
void printbin(int x){
	for(int i=x&0x7FFFFFFF;i;i>>=1)
	printf(i&x?"1":"0");
}
int sameline(const pt& p1, const pt& p2, const pt& p3){
	int d1, d2, da1, da2, db1, db2;
	d1 = p1.X * p1.X * p2.X - p2.X * p2.X * p1.X;
	d2 = p1.X * p1.X * p3.X - p3.X * p3.X * p1.X;
	da1 = p1.Y * p2.X - p2.Y * p1.X;
	da2 = p1.Y * p3.X - p3.Y * p1.X;
	db1 = p1.X * p1.X * p2.Y - p2.X * p2.X * p1.Y;
	db2 = p1.X * p1.X * p3.Y - p3.X * p3.X * p1.Y;
	if(d1*da2 == d2*da1 && d1*db2 && d2*db1)return 1;
	else return 0;
}
int down(int bits);
int dp[1<<25]={}, n;
pt point[1005]={};

int main(){
	int T; cin >> T;
	while(T--){
		memset(dp,0,sizeof(dp));
		dp[0] = 0;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> point[i].X >> point[i].Y ;
		for(int i = 1; i < 1<<n; i++){
			int tmp = i, j;
			vector<int> tpt;
			for(j = 0;; j++, tmp=tmp>>1)if(tmp%2) tpt.push_back(j);
			for(int p1 = 0; p1 < tpt.size(); p1++)for(int p2 = p1+1; p2 < tpt.size(); p2++){
				for(int p3 = p2+1; p3 < tpt.size(); p3++){
					
				}
			}
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}

/*
2
7
1 3
2 4
3 3
2 6
4 8
1 1
1 2
6
1 8
2 12
3 12
4 4
5 5
6 6
*/
