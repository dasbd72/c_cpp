#include<stdio.h>
#include<string.h> 
int H,W,pool[1000][10000],runned[1000][10000],tot;

int flood(int,int);
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&H,&W);
		for(int y=0;y<H;y++){
			char block[10000];
			scanf("%s",block);
			for(int x=0;x<W;x++){
				if(block[x]=='.')pool[y][x]=1;
				else pool[y][x]=0;
			}
		}
		tot=0;
		memset(runned,0,sizeof(runned));
		for(int y=0;y<H;y++)for(int x=0;x<W;x++)if(!runned[y][x]){
			if(pool[y][x]){
				tot++;
				flood(y,x);
			}
			
		}
		printf("%d\n",tot);
	}
	
}
int flood(int y,int x){
	runned[y][x]=1;
	if(y!=0){
		if(pool[y-1][x]&&!runned[y-1][x])flood(y-1,x);
	}
	if(y!=H-1){
		if(pool[y+1][x]&&!runned[y+1][x])flood(y+1,x);
	}
	if(x!=0){
		if(pool[y][x-1]&&!runned[y][x-1])flood(y,x-1);
	}
	if(x!=W-1){
		if(pool[y][x+1]&&!runned[y][x+1])flood(y,x+1);
	}
	return 0;
}
