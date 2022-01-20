#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct line{
	int num;
	line *next;
};
int main(){
	int N,M,i,id,j;
	char code[5]={}; 
	line *ptr[101],*ptf[101];
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		line *create=new line();
		create->next=NULL;
		ptr[i]=create;
		ptf[i]=create;
	}
	while(M--){
		scanf("%s",&code);
		if(code[0]=='A'){
			scanf("%d %d",&i,&id);
			line *add=ptr[i];
			add->num=id;
			add->next=new line();
			add=add->next;
			ptr[i]=add;
			add->next=NULL;
		}
		else if(code[0]=='L'){
			scanf("%d",&i);
			line *leave=ptf[i];
			if(ptr[i]==ptf[i]){
				printf("queue %d is empty!\n",i);
			}
			else{
				leave=leave->next;
				ptf[i]=leave;
			}
		}
		else if(code[0]=='J'){
			scanf("%d %d",&i,&j);
			line *tojoin=ptr[j];
			if(ptr[i]!=ptf[i]&&ptr[j]!=ptf[j]){
				tojoin->num=ptf[i]->num;
				tojoin->next=ptf[i]->next;
				ptr[j]=ptr[i];
			}
			else if(ptr[i]!=ptf[i]&&ptr[j]==ptf[j]){
				ptr[j]=ptr[i];
				ptf[j]=ptf[i];
			}
			line *nl=new line();
			nl->next=NULL;
			ptr[i]=nl;
			ptf[i]=nl;
		}
	}
	for(int i=1;i<=N;i++){
		printf("queue %d:",i);
		line *use=ptf[i];
		if(ptf[i]==ptr[i])printf(" empty\n");
		else{
			while(use!=ptr[i]){
				printf(" %d",use->num);
				use=use->next;
			}
			printf("\n");
		}
		
	}
	return 0;
}
