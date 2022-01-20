#include<stdio.h>
#include<string.h>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#define MAX 100000000
using namespace std;
int N, M, x, y;
struct people{
	int aware,exist;
	vector<people*> relate;
}*ptr[1005];

int main(){
	scanf("%d %d",&N,&M);
	for(int i = 1;i<=N;i++){
		scanf("%d",&x);
		ptr[i] = new people();
		ptr[i]->aware = x;
		ptr[i]->exist = 1; 
	}
	for(int i = 0;i<M;i++){
		scanf("%d %d",&x,&y);
		ptr[x] -> relate.push_back(ptr[y]);
		ptr[y] -> relate.push_back(ptr[x]);
	}
	int ans=0;
	for(int iN = 1;iN<=N;iN++){
		int risk[1005]={};
		int tmp=MAX, tmpi;
		for(int i = 1;i<=N;i++)if(ptr[i]->exist){
			for(int j = 0 ; j<ptr[i]->relate.size() ; j++){
				if(ptr[i]->relate[j]->exist)risk[i]+=ptr[i]->relate[j]->aware;
			}
			if(risk[i]<tmp){
				tmp=risk[i];
				tmpi=i;
			}
		}
		ans+=tmp;
		ptr[tmpi]->exist=0;
		printf("kill %d\n",tmpi);
	}
	printf("%d\n",ans);
}
