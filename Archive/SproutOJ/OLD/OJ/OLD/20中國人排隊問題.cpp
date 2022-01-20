#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct line{
	int num;
	line *next;
};

int team[1000000]={};
int main(){
	int L=1,N;
	while(scanf("%d",&N)!=EOF){
		memset(team,0,sizeof(team));
		int tman[1000]={},K,Ki,x;
		char code[8]={};
		line *ptlast[1000]={};
		line *head=new line();
		line *current=head;
		
		printf("Line #%d\n",L++);
		for(int i=1;i<=N;i++){
			scanf("%d",&K);
			while(K--){
				scanf("%d",&Ki);
				team[Ki]=i;
			}
		}
		
		while(scanf("%s",&code)&&code[0]!='S'){
			if(code[0]=='E'){
				scanf("%d",&x);
				if(team[x]!=0&&tman[team[x]]>0){
					tman[team[x]]++; 
					line *old=ptlast[team[x]];
					line *insert=new line();
					insert->num=x;
					insert->next=old->next;
					old->next=insert;
					ptlast[team[x]]=insert;
					if(insert->next==NULL){
						current=insert;
					}
				}
				else{
					current->next=new line();
					current=current->next;
					current->num=x;
					current->next=NULL;
					if(team[x]){
						tman[team[x]]++;
						ptlast[team[x]]=current;
					}
				}
			}
			else if(code[0]='D'){
				head=head->next;
				printf("%d\n",head->num);
				if(team[head->num]){
					tman[team[head->num]]--;
				}
				
			}
		}
	}
	return 0;
}
