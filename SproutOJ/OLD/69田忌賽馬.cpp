#include<stdio.h>
#include<string.h>
#include <algorithm>
#define MAXN 100000000
using namespace std;
int T,N,K,zeros,haj;
long long enespeed[10005]={},myspeed[10005]={},grow[10005]={},copyhorse[10005]={};
int _race(long long arrh[]);
int main(){
	scanf("%d",&T);
	while(T--){
		zeros=0;//noproblem
		memset(enespeed,0,sizeof(enespeed));
		memset(myspeed,0,sizeof(myspeed));
		memset(grow,0,sizeof(grow));
		scanf("%d %d",&N,&K);
		for(int my=0;my<N;my++){
			scanf("%d %d",&myspeed[my],&grow[my]);
			if(grow[my]==0)zeros++;
		}
		for(int ene=0;ene<N;ene++){
			scanf("%d",&enespeed[ene]);
		}
		sort(enespeed,enespeed+N);
		
		for(int i=0;i<N;i++){
			copyhorse[i]=myspeed[i]+grow[i]*MAXN;
		}
		haj=_race(copyhorse);
		if(haj<K){
			printf("-1\n");
		}
		else{
			int l=0,r=MAXN,mid;
    	while(l+1!=r){
				mid = (l + r)/2;
				for(int i=0;i<N;i++){
					copyhorse[i]=myspeed[i]+grow[i]*mid;
				}
				haj=_race(copyhorse);
				if(haj>=K)r=mid;
    		else l=mid;
    	}
    	for(int i=0;i<N;i++){
				copyhorse[i]=myspeed[i]+grow[i]*l;
			}
			haj=_race(copyhorse);
			if(haj>=K)printf("%d\n",l);
			else printf("%d\n",r);
		}
	}
}

int _race(long long arrh[]){
	int tot=0,my=0,ene=0;
	sort(arrh,arrh+N);
	while(arrh[my]<=enespeed[0]&&my<N){
		my++;
	}
	for(int i=my;i<N;i++){
		if(arrh[i]>enespeed[ene]){
			tot++;
			ene++;
		}
	}
	return tot;
}
