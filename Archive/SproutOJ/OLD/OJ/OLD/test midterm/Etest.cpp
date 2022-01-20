#include<stdio.h>
#include<string.h>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int N, x;
priority_queue<int,vector<int>,greater<int> > num;
char command[5];
int main(){
	scanf("%d",&N);
	for(int iN = 0;iN<N;iN++){
		scanf("%s",command);
		if(command[1] == 'u'){
			scanf("%d",&x);
			num.push(x);
		}
		else{
			if(!num.empty())num.pop();
		}
	}
	int ans=0;
	while(!num.empty()){
		ans+=num.top();
		num.pop();
	}
	printf("%d",ans);
}
