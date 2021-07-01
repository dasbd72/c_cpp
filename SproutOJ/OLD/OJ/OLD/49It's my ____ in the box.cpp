#include<stdio.h>
#include<vector>
using namespace std;
int T,n,m,toget,toput,q,x;
struct box{
	int _runned,_down;
	vector<box*> _inside;
};
box *ptr[100001];
int dfs(box*);
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<=n;i++){
			box *_vacant=new box();
			ptr[i]=_vacant;
			_vacant->_down=1;
			_vacant->_runned=0;
		}
		
		while(m--){
			scanf("%d %d",&toget,&toput);
			(ptr[toget]->_inside).push_back(ptr[toput]);
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d",&x);
			printf("%d\n",dfs(ptr[x]));
		}
	}
	return 0;
}
int dfs(box *num){
	if(num->_runned)return num->_down;
	if(num->_inside.empty())return 1;
	else{
		for(int i2=0;i2<num->_inside.size();i2++){
			num->_down+=dfs(num->_inside[i2]);
		}
		num->_runned=1;
		return num->_down;
	}
}
