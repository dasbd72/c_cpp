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
	pair<long long,long long> pt[1005]={};
	int N,x,y;
	vector<long long> len;
	len.clear();
	
	cin >> N;
	for(int i = 0;i < N;i++){
		cin >> x >> y;
		pt[i] = make_pair(x , y);
	}
	for(int i = 0;i < N;i++)for(int j = i + 1;j < N;j++){
		long long a = pt[j].X-pt[i].X, b = pt[j].Y-pt[i].Y;
		len.push_back(a*a + b*b);
		//len.push_back(pow(pt[j].X-pt[i].X,2) + pow(pt[j].Y-pt[i].Y,2));
		//cout<<len.back()<<" "<<pt[i].X<<" "<<pt[i].Y<<" "<<pt[j].X<<" "<<pt[j].Y<<" "<< '\n';
	}
	
	sort(len.begin(), len.end());
	long long tmp = len[0];
	int ans = 0, count = 1;
	for(int i = 1;i < len.size();i++){
		if(len[i] == tmp)count++;
		else{
			tmp = len[i];
			ans+=(count*(count-1)/2);
			count = 1;
		}
	}
	ans+=(count*(count-1)/2);
	cout << ans << endl;
	return 0;
}

