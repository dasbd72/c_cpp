#include<stdio.h>
#include<stack>
#include<string.h>
#define MAXN 1000000+5
using namespace std;
int main(){
	int T,N;
	long long scx,tmp,ans,repeat;
	for(scanf("%d",&T);T;T--){
		stack<long long> wa;
		ans=0;
		scanf("%d",&N);
		for(int iN=0;iN<N;iN++){
			scanf("%lld",&scx);
			while(!wa.empty()&&scx>wa.top()){
				tmp=wa.top();
				wa.pop();
				ans++;
				if(!wa.empty()&&wa.top()>tmp)ans++;
				else if(!wa.empty()&&wa.top()==tmp){
					repeat=1;
					while(!wa.empty()&&wa.top()==tmp){
						repeat++;
						wa.pop();
					}
					ans+=(repeat*(repeat-1)/2);
					ans+=repeat-1;
					if(!wa.empty())ans+=repeat;
				}
			}
			wa.push(scx);
		}
		if(wa.size()>1)while(wa.size()>1){
			tmp=wa.top();
			wa.pop();
			ans++;
			if(!wa.empty()&&wa.top()==tmp){
				repeat=1;
				while(!wa.empty()&&wa.top()==tmp){
					repeat++;
					wa.pop();
				}
				ans+=(repeat*(repeat-1)/2)-1;
				if(!wa.empty())ans+=repeat;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
