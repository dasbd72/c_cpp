#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long M, N, X, af = 0, al = 0;
	cin >> M >> N;
	X = M * N * (N + M - 2);
	cout << (X>>1) << endl;
	
	return 0;
}

