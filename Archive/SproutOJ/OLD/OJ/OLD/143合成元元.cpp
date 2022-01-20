#include<stdio.h>
#include<string.h>
#include<cmath>
#define MAXN 2147483647
using namespace std;
int N, a[1005] = {};
int awe[1005][1005] = {};
int dp(int L,int R){
	if(L == R)return 0;
	if(awe[L][R] != 0)return awe[L][R];
	int tmp = MAXN, tmpL, tmpR, count = 0, tcount;
	for(int i = L;i <= R;i++)count+=a[i];
	for(int mid = L;mid<R;mid++){
		tcount = count;
		
		tmpL = dp(L, mid), tmpR = dp(mid+1, R);
		if(L!=mid)tcount+=tmpL;
		if(mid+1!=R)tcount+=tmpR;
		tmp = tcount < tmp ? tcount : tmp;
	}
	awe[L][R] = tmp;
	return tmp;
}
int main(){
	int T,ans;
	for(scanf("%d",&T);T;T--){
		memset(awe,0,sizeof(awe));
		scanf("%d",&N);
		for(int iN = 1;iN <= N;iN++){
			scanf("%d",&a[iN]);
		}
		ans=dp(1,N);
		printf("%d\n",ans);
	}
}
