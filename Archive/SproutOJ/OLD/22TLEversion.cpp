#include<stdio.h>
#include<algorithm>
#define MAXN 1000000+5
using namespace std;
int T,N,wa[MAXN];//wa=warrior
int maxx,tmp,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		ans=0;
		for(int iN=0;iN<N;iN++){
			scanf("%d",&wa[iN]);
		}
		for(int i=0;i<N-1;i++){
			tmp=wa[i];
			maxx=wa[i+1];
			ans++;
			for(int j=i+2;j<N;j++){
				if(maxx<=tmp&&maxx<=wa[j])ans++;
				maxx=wa[j]>maxx?wa[j]:maxx;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
