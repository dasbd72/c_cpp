#include<stdio.h>
#include<string.h>
int flag=0,k,luckyinput[13],ans[6];
int chose[13]={};
int _bt(int,int);
int main(){
	while(scanf("%d",&k)&&k!=0){
		if(flag)printf("\n");
		else flag=1;
		for(int i=0;i<k;i++){
			scanf("%d",&luckyinput[i]);
		}
		memset(chose,0,sizeof(chose));
		_bt(-1,0);
	}
}
int _bt(int n,int l){
	if(l==6){
		for(int i=0;i<6;i++){printf("%d",ans[i]);if(i==5)printf("\n");else printf(" ");}
		return 0;
	}
	for(int i=l;i<k;i++)if(!chose[i]&&5-l<k-i&&n<=luckyinput[i]){
		chose[i]=1;
		ans[l]=luckyinput[i];
		_bt(ans[l],l+1);
		chose[i]=0;
	}
}

