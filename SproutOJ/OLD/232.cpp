#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	int N, M, Q;
	long long point[100005]={};
	char command[6];
	cin >> N >> M >> Q;
	vector<long long*> comment[M+1];
	for(int i = 1;i <= N;i++) cin >> point[i];
	for(int i = 1, x, y;i <= M;i++){
		cin >> x;
		while(x--){
			cin >> y;
			comment[i].push_back(&point[y]);
		}
	}
	while(Q--){
		int x, add;
		cin >> command;
		if(command[0] == 'A'){
			cin >> x >> add;
			for(int j = 0;j < comment[x].size();j++){
				*comment[x][j] += add;
			}
		}else{
			cin >> x;
			long long ans = 0;
			for(int j = 0;j < comment[x].size();j++){
				ans += *comment[x][j];
			}
			cout << ans << endl;
		}
		
	}
	return 0;
}
/*
5 3 7
1 2 3 4 5
3 1 2 3
3 5 1 3
2 2 5
QUERY 1
QUERY 2
QUERY 3
ADD 1 10
QUERY 1
QUERY 2
QUERY 3
*/
