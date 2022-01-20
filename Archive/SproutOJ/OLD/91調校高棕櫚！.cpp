#include <stdio.h>
#include <string.h>
int T,fac[10];
long long N;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(fac,0,sizeof(fac));
		scanf("%lld",&N);
		if(N==1){
			printf("1\n");
			continue;
		}
		for(int i=9;i>=2;i--)while(N%i==0){
			N/=i;
			fac[i]++;
		}
		if(N!=1){
			printf("-1\n");
			continue;
		}
		else if(N==1)for(int i=2;i<=9;i++){
			while(fac[i]){
				printf("%d",i);
				fac[i]--;
			}
		}
		printf("\n");
	}
}
