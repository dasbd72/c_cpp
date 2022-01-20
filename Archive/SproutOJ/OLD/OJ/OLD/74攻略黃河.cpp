#include<stdio.h>
#include<string.h>
using namespace std;
int N;
long long stone[1000005];
int main(){
	int scT;
	for(scanf("%d",&scT);scT;scT--){
		memset(stone,0,sizeof(stone));
		scanf("%d",&N);
		for(int iN=0;iN<N;iN++){
			scanf("%lld",&stone[iN]);
		}
		int len=1,tall=1,i=1;
		long long tmp;
		tmp=stone[0];
		while(tmp<stone[i]){
			tmp=stone[i++];
		}
		while(i!=N){
			if(tall){
				if(tmp>=stone[i]){
					while(tmp>=stone[i]){
						tmp=stone[i++];
						if(i==N)goto end;
					}
					tall=0;
					len++;
				}
			}
			else{
				if(tmp<=stone[i]){
					while(tmp<=stone[i]){
						tmp=stone[i++];
						if(i==N)goto end;
					}
					tall=1;
					len++;
				}
			}
		}
		end:;
		if(tall)printf("%d\n",len);
		else printf("%d\n",len+1);
	}return 0;
}
