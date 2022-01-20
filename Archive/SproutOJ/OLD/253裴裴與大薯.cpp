#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

long long dp[2][5005] = {{1},{1}};
int inp[5005];
queue<int> que[2];
int main() {
	int N;cin >> N;
	for(int i = 0;i < N;i++){
		cin >> inp[i];
	}
	que[1].push(0);
	for(int i = 1;i < N;i++){
		
	}
	return 0;
}

