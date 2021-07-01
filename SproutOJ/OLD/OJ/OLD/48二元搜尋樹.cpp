#include<stdio.h>
#include<vector>
using namespace std;
struct tree{
	int num;
	tree *lchild,*rchild;
};
void dfs(tree* branch);
int ki,cvec=0;
vector<int> mid;
tree *nf[100000]={};
int main(){
	tree *root=new tree();
	tree *node=root;
	root->lchild=NULL;
	root->rchild=NULL;
	scanf("%d",&root->num);
	nf[root->num]=root;
	mid.push_back(root->num);
	while(scanf("%d",&ki)!=EOF){
		if(ki<node->num){
			//printf("%d->l\ncvev=%d\n",node->num,cvec);
			node->lchild=new tree();
			node=node->lchild;
			node->num=ki;
			node->lchild=NULL;
			node->rchild=NULL;
			nf[node->num]=node;
			cvec++;
			mid.push_back(node->num);
			
		}
		else if(ki>node->num){
			
			while(cvec!=0&&ki>mid[cvec-1]){
				//printf("midcvec-1:%d\n",mid[cvec-1]);
				mid.pop_back();
				cvec--;
			}
			node=nf[mid.back()];
			//printf("%d->r\ncvev=%d\n",node->num,cvec);
			node->rchild=new tree();
			node=node->rchild;
			node->num=ki;
			node->lchild=NULL;
			node->rchild=NULL;
			nf[ki]=node;
			mid.pop_back();
			mid.push_back(ki);
		}
	}
	dfs(root);
	return 0;
}
void dfs(tree* branch){
	if(branch->lchild!=NULL)dfs(branch->lchild);
	if(branch->rchild!=NULL)dfs(branch->rchild);
	printf("%d\n",branch->num);
}
