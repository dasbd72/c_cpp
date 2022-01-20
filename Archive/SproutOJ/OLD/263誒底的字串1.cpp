#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	string A;
	int min = 0x7FFFFFFF, tmp;
	pair<int, int> least;
	vector<int> re;
	cin >> A;
	for(int i = 0; i < A.size(); i++) if(A[i] == A[0]) re.push_back(i);
	for(int i = 1; i < re.size();i++){
		tmp = 0;
		for(int a = 0, b = re[i]; A[a]==A[b]; a++, b++)tmp++;
		if(tmp < least.second){
			least.second = tmp;
			least.first = re[i];
		}
	}
	cout << least.second;
	return 0;
}

