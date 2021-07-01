#include<stdio.h>
#include<vector>
#include <queue>
using namespace std;

int T,n,x,tmp,tmpi;
vector<int> arr;
int main() {
	priority_queue<int, vector<int>, greater<int> > que;
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		if(n == 1) {
			scanf("%d",&x);
			que.push(x);
		}
		else {
			if(que.empty())printf("empty!\n");
			else {
				printf("%d\n",que.top());
				que.pop();
			}
		}
	}
	return 0;
}

