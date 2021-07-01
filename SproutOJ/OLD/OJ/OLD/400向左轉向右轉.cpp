#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define X first
#define Y second
using namespace std;
int main() {
	int N;
	int TR = 0,TL = 0,TB = 0;
	long long x[3]={}, y[3]={};
	const double eps = 1e-9;
	cin >> N;
	for(int i = 0;i < N && i < 2;i++){
		cin >> x[i] >> y[i];
	}
	
	for(int i = 2;i < N;i++){
		cin >> x[2] >> y[2];
		pair<long long, long long> a, b;
		a = make_pair(x[1]-x[0], y[1]-y[0]);
		b = make_pair(x[2]-x[1], y[2]-y[1]);
		long long cross = a.X*b.Y - a.Y*b.X;
		long long dot = a.X*b.X + a.Y*b.Y;
		long long sqrtcos = (dot*dot)/((a.X*a.X+a.Y*a.Y)*(b.X*b.X+b.Y*b.Y));
		if(cross > 0)TL++;
		else if(cross < 0)TR++;
		else if(dot < 0 && sqrtcos == 1)TB++;
		x[0] = x[1], x[1] = x[2];
		y[0] = y[1], y[1] = y[2];
	}
	
	cout << TL <<" "<< TR <<" "<< TB << "\n";
	return 0;
}

