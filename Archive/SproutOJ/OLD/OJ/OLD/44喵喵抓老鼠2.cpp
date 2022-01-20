#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue> 
using namespace std;
struct data{
	int x,y,l;
};
char MAP[101][101];
bool run[101][101];
int X[4]={0,1,0,-1},Y[4]={1,0,-1,0},ans;
int main(){
	int N,W;
	while(scanf("%d",&N)&&N!=0){
		queue<data> now;
		for(int i=0;i<N;i++)scanf("%s",MAP[i]);
		W=strlen(MAP[0]);
		fill((bool*)run,(bool*)run+101*101,true);
		for(int y=0;y<N;y++)for(int x=0;x<W;x++)if(MAP[y][x]=='K'){
			now.push((data){y,x,0});
			run[y][x]=false;
			goto start;
		}
		start:;
		ans=-1;
		while(!now.empty()){
			int x=now.front().x,y=now.front().y,l=now.front().l;
			now.pop();
			for(int i=0;i<4;i++){
				if(run[x+X[i]][y+Y[i]]){
					run[x+X[i]][y+Y[i]]=false;
					if(MAP[x+X[i]][y+Y[i]]=='#')continue;
					if(MAP[x+X[i]][y+Y[i]]=='.')now.push((data){x+X[i],y+Y[i],l+1});
					if(MAP[x+X[i]][y+Y[i]]=='@'){
						ans=l+1;
						goto end;
					}
				}
			}
		}
		end:;
		if(ans==-1)printf("= =\"\n");
		else printf("%d\n",ans);
	}
	return 0;
}
