#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	int N,flower[200005],scx,tmp=0,maxi;
	stack<int> fl;
	scanf("%d",&N);
	for(int iN=1;iN<=N;iN++){
		scanf("%d",&flower[iN]);
		if(flower[iN]>tmp){
			tmp=flower[iN];
			maxi=iN;
		}
	}
	tmp=0;
	for(int k=1;k<maxi;k++){
		
		while(!fl.empty()&&flower[k]>fl.top()&&flower[k]>tmp){
			fl.pop();
		}
		tmp=flower[k]>tmp?flower[k]:tmp;
		fl.push(flower[k]);
	}
	printf("%d\n",fl.size());
} 
