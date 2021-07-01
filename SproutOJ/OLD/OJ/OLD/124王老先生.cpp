#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stack>
using namespace std;
struct pos{
	int _x,_y;
};
int _N,runned;
int fill(int,int,int,int,int);
void solve(int N,int X,int Y){
	_N=N;
	runned=0;
	fill(1,1,X,Y,N);
}
/*
void Report(int x1,int y1,int x2,int y2,int x3,int y3){
	printf("Report(%d,%d,%d,%d,%d,%d)",x1,y1,x2,y2,x3,y3);
}
*/
int fill(int linex,int liney,int x,int y,int farmsize){
	if(farmsize==1)return 0;
	stack<pos> answer;
	int s=farmsize/2;
	int centerx=linex+s,centery=liney+s;
	//左上 左下 右上 右下 
	if(x<centerx&&y<centery){
		fill(linex,liney,x,y,s);
	}else{
		answer.push((pos){centerx-1,centery-1});
		fill(linex,liney,centerx-1,centery-1,s);
	}
	if(x>=centerx&&y<centery){
		fill(centerx,liney,x,y,s);
	}else{
		answer.push((pos){centerx,centery-1});
		fill(centerx,liney,centerx,centery-1,s);
	}
	if(x<centerx&&y>=centery){
		fill(linex,centery,x,y,s);
	}else{
		answer.push((pos){centerx-1,centery});
		fill(linex,centery,centerx-1,centery,s);
	}
	if(x>=centerx&&y>=centery){
		fill(centerx,centery,x,y,s);
	}else{
		answer.push((pos){centerx,centery});
		fill(centerx,centery,centerx,centery,s);
	}
	int xx[3],yy[3];
	for(int i=0;i<3;i++){
		xx[i]=answer.top()._x;
		yy[i]=answer.top()._y;
		answer.pop();
	}
	Report(xx[0],yy[0],xx[1],yy[1],xx[2],yy[2]);
}
/*
int main(){
	solve(4,3,4);
}
*/
