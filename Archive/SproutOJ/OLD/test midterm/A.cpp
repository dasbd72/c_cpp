#include<stdio.h>
#include<string.h>
#include<cmath>
#include<stack>
#include<queue>
#define MAX 1005
using namespace std;
int YY[4]={1,0,-1,0}, XX[4]={0,1,0,-1};//u r d l
int n, m, map[MAX][MAX] = {};
int runned[MAX][MAX] = {},hl,ll;
int highland=0,lowland=0;
struct pos{
	int _y,_x;
};
queue<pos> que, H;

int main(){
	scanf("%d %d",&n,&m);
	for(int iy = 0;iy<n;iy++)for(int ix = 0;ix<m;ix++){
		scanf("%d",&map[iy][ix]);
	}
	for(int iy = 0;iy<n;iy++)for(int ix = 0;ix<m;ix++)if(!runned[iy][ix]){
		H.push((pos){iy,ix});
		hl=0,ll=0;
		while(!H.empty()){
			int tmpy=H.front()._y,tmpx=H.front()._x;
			H.pop();
			runned[tmpy][tmpx] = 1;
			for(int way = 0;way<4;way++){
				int y = tmpy + YY[way], x = tmpx + XX[way];
				if(y>=0 && y<n && x>=0 && x<m){
					if(map[tmpy][tmpx]==map[y][x] && !runned[y][x])H.push((pos){y,x});
					else if(map[tmpy][tmpx]>map[y][x])hl=1;
					else if(map[tmpy][tmpx]<map[y][x])ll=1;
				}
			}
		}
		if(hl==1&&ll==0)highland++;
		else if(hl==0&&ll==1)lowland++;
	}
	printf("%d %d\n",lowland,highland);
}
