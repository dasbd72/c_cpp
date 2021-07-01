#include<stdio.h>
#include <algorithm>
#include <queue>
#include<vector>
using namespace std;
long long scN,scx;
long long a,ans;
int main(){
	while(scanf("%lld",&scN)&&scN!=0){
		priority_queue<long long, vector<long long>, greater<long long> > que;
		for(int iN=0;iN<scN;iN++){
			scanf("%lld",&scx);
			que.push(scx);
		}
		ans=0;
		while(que.size()!=1){
			a=que.top();
			que.pop();
			a+=que.top();
			que.pop();
			ans+=a;
			if(que.empty())break;
			que.push(a);
		}
		printf("%lld\n",ans);
	}
}
