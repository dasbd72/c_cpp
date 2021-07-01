#include<stdio.h>
#include<string.h>
#define MAXN 1000005
int ans[MAXN];
void Sep(int U,int D){
	if(U == D)return;
	int Mid = (U + D) / 2;
	
	Sep(U , Mid);
	Sep(Mid + 1 , D);
}
int _Find(int _row,int L,int R){
	int tmp = 0 , tmpi , getv;
	for(int i = L ; i <= R ; i++){
		getv = GetVal(_row , i);
		if(getv>tmp){
			tmp = getv;
			tmpi = i;
		}
	}
}
void solve(int N,int M){//[1~N][1~M]
	memset(ans , 0 , sizeof(ans));
	int midrow = (1 + N) / 2;
	ans[midrow] = _Find(midrow , 1 , M);
	Sep(1 , N);
}
