#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int n,m,l1,l2,rainbow;
struct people{
	int _num,_color;
	vector<int> nodes;
}*ptr[200005];
void dfs(int,int);
int main(){
	while(scanf("%d",&n)&&n!=0){
		for(int in=0;in<n;in++){
			people *person=new people();
			ptr[in]=person;
			ptr[in]->_color=0;
			ptr[in]->_num=in;
		}
		rainbow=0;
		scanf("%d",&m);
		for(int im=0;im<m;im++){
			scanf("%d %d",&l1,&l2);
			ptr[l1]->nodes.push_back(l2);
			ptr[l2]->nodes.push_back(l1);
		}
		for(int in=0;in<n;in++){
			if(!ptr[in]->_color){
				dfs(in,1);
			}
		}
		if(rainbow)printf("RAINBOW.\n");
		else printf("NORMAL.\n");
	}
}
void dfs(int now,int _col){
	ptr[now]->_color=_col;
	for(int in;in<ptr[now]->nodes.size();in++){
		int next=ptr[now]->nodes[in];
		if(!ptr[next]->_color){
			if(_col==1)dfs(next,2);
			else       dfs(next,1);
		}
		else{
			if(ptr[next]->_color==_col)rainbow=1;
		}
	}
}
