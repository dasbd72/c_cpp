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
		int x;
		vector<int> b,vec;
		
		cin >> N >> M;
		for(int i = 0;i < N;i++){
			cin >> x;
			if(x*2>=M) b.push_back(x*2);
			if(x  >=M) b.push_back(x);
		}
		if(b.empty()){
			printf("0\n");
			continue;
		}
		vec.push_back(b[0]);
		for(int i = 1;i < b.size();i++){
			if(b[i]>=vec.back())vec.push_back(b[i]);
			else *upper_bound( vec.begin(), vec.end(), b[i]) = b[i];
		}
		cout << vec.size() << endl;
	}
	return 0;
}

