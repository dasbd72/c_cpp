#include<stdio.h>
#include<vector>
using namespace std;
int T,N,a,b;
int i,i2;
int ans,balance;
vector<int> tree[100005];
int son[100005];
void dfs(int,int);
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for (int i=0;i<=N-1;i++){
            tree[i].clear();
        }
		for(i=0;i<N-1;i++){
			scanf("%d %d",&a,&b);
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		balance=1e9;
		dfs(0,-1);
		printf("%d\n",ans);
	}
	return 0;
}

void dfs(int v,int fa){
	son[v]=0;
	int d=tree[v].size();
	int pre_balance=0;
	for(int i=0;i<d;i++){
		int k=tree[v][i];
		if(k!=fa){
			dfs(k,v);
			son[v]+=son[k]+1;
			pre_balance=max(pre_balance,son[k]+1);
		}
	}
	pre_balance=max(pre_balance,N-son[v]-1);
	if(pre_balance<balance||(pre_balance==balance&&v<ans)){
		ans=v;
		balance=pre_balance;
	}
}

