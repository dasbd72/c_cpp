#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	int N, ans = 0;
	double v[505]={};
	const double ept = 1e-10;
	cin >> N;
	for(int i = 0;i < N;i++) {
		cin >> v[i];
	}
	sort(v,v+N);
	for(int i = 0;i < N;i++)for(int j = 0;j < N;j++)
	for(int t = 0;t < N;t++){
		if((v[i] + v[j] == v[t])||(v[i] + v[j] - ept <= v[t] && v[i] + v[j] + ept >= v[t]))ans++;
	}
	cout << ans << endl;
	return 0;
}

