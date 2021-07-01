#include<stdio.h>
#define MAXN 10000019
int N;
long long arr[1000005],tmparr[1000005],ans;
void MS(int,int);
int main(){
	scanf("%d",&N);
	for(int iN=0;iN<N;iN++){
		scanf("%lld",&arr[iN]);
	}
	ans=0;
	MS(0,N-1);
	printf("%lld\n",ans%MAXN);
}
void MS(int first,int last){
	if(first==last)return;
	int mid=(first+last)/2;
	MS(first,mid);
	MS(mid+1,last);
	
	int fi=first,mi=mid+1,i=0,set;
	long long tot=0,num=0;
	for(int j=fi;j<=mid;j++){
		tot+=arr[j];
		num++;
	}
	while(fi<=mid&&mi<=last){
		if(arr[fi]>arr[mi]){
			ans+=tot;
			ans+=arr[mi]*num;
			tmparr[i++]=arr[mi++];
			ans%=MAXN;
		}
		else if(arr[fi]<=arr[mi]){
			tot-=arr[fi];
			num--;
			tmparr[i++]=arr[fi++];
		}
	}
	if(fi<=mid)while(fi<=mid)
		tmparr[i++]=arr[fi++];
	else if(mi<=last)while(mi<=last)
		tmparr[i++]=arr[mi++];
	for(i=0,set=first;set<=last;set++,i++){
		arr[set]=tmparr[i];
	}
}
