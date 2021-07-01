#include<stdio.h>
int N,M,T,X,die[100000]={};
struct rank{
	int num;
	rank *front;
	rank *back;
};
rank *ptr[100000]={};
int main(){
	scanf("%d %d",&N,&M);
	rank *first=new rank();
	rank *last=new rank();
	last->num=-1;
	first->front=NULL;
	last->back=NULL;
	rank *make=new rank();
	make->num=1;
	make->front=first;
	first->back=make;
	ptr[1]=make;
	for(int i=2;i<=N;i++){
		make->back=new rank();
		make=make->back;
		make->front=ptr[i-1];
		make->num=i;
		ptr[i]=make;
	}
	last->front=make;
	make->back=last;
	
	
	while(M--){
		scanf("%d %d",&T,&X);
		if(T==0){
			rank *kill=ptr[X];
			rank *bkill=kill->back;
			rank *fkill=kill->front;
			fkill->back=bkill;
			bkill->front=fkill;
		}
		else if(T==1){
			rank *rush=ptr[X];
			rank *frush=rush->front;
			rank *brush=rush->back;
			if(frush!=first){
				rank *ffrush=frush->front;
				brush->front=frush;
				frush->back=brush;
				frush->front=rush;
				rush->back=frush;
				rush->front=ffrush;
				ffrush->back=rush;
			}
		}
	}
	
	
	while(first->back!=last){
		first=first->back;
		if(first->back==last){
			printf("%d\n",first->num);
		}
		else printf("%d ",first->num);
		
	}
	return 0;
} 
