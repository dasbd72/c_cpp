#include<stdio.h>
#include<queue>
#include<string.h>
#define MAXN 1005
using namespace std;
int T,N,scY,scX;
char col,askedcol;
char cloth[MAXN][MAXN];
int start[3][2],runY[MAXN][MAXN],runB[MAXN][MAXN],runR[MAXN][MAXN];
int Y[8]={-1,-1,-1,0,1,1,1,0},X[8]={-1,0,1,1,1,0,-1,-1};
int lastnum,ansnum;
struct pos{
	int _y,_x;
};
int check();
void print(); 
char combine(char,char);
int main(){
	for(scanf("%d",&T);T;T--){
		queue<pos> cY,cB,cR;
		memset(runY,0,sizeof(runY));
		memset(runB,0,sizeof(runB));
		memset(runR,0,sizeof(runR));
		memset(cloth,'X',sizeof(cloth));
		scanf("%d\n",&N);
		for(int in=0;in<3;in++){
			scanf("%c %d %d\n",&col,&scX,&scY);
			cloth[scY][scX]=combine(col,cloth[scY][scX]);
			if(col=='Y'){
				start[0][0]=scY;
				start[0][1]=scX;
			}
			if(col=='B'){
				start[1][0]=scY;
				start[1][1]=scX;
			}
			if(col=='R'){
				start[2][0]=scY;
				start[2][1]=scX;
			}
		}
		runY[start[0][0]][start[0][1]]=1;
		runB[start[1][0]][start[1][1]]=1;
		runR[start[2][0]][start[2][1]]=1;
		cY.push((pos){start[0][0],start[0][1]});
		cB.push((pos){start[1][0],start[1][1]});
		cR.push((pos){start[2][0],start[2][1]});
		scanf("%c",&askedcol);
		if(askedcol=='D'){
			printf("%d\n",N*N);
			continue;
		}
		ansnum=0,lastnum=0;
		if(askedcol==cloth[start[0][0]][start[0][1]]
		 ||askedcol==cloth[start[1][0]][start[1][1]]
		 ||askedcol==cloth[start[2][0]][start[2][1]])ansnum++;
		while(!cY.empty()||!cB.empty()||!cR.empty()){
			int Ytimes=cY.size(),Btimes=cB.size(),Rtimes=cR.size();
			for(int yy=0;yy<Ytimes;yy++){
				int cYy=cY.front()._y,cYx=cY.front()._x;
				cY.pop();
				for(int i=0;i<8;i++){
					int nYy=cYy+Y[i],nYx=cYx+X[i];
					if(nYy>=0&&nYy<N&&nYx>=0&&nYx<N&&!runY[nYy][nYx]){
						runY[nYy][nYx]=1;
						if(cloth[nYy][nYx]==askedcol)ansnum--;
						cloth[nYy][nYx]=combine('Y',cloth[nYy][nYx]);
						cY.push((pos){nYy,nYx});
						if(cloth[nYy][nYx]==askedcol)ansnum++;
					}
				}
			}
			for(int bb=0;bb<Btimes;bb++){
				int cBy=cB.front()._y,cBx=cB.front()._x;
				cB.pop();
				for(int i=0;i<8;i++){
					int nBy=cBy+Y[i],nBx=cBx+X[i];
					if(nBy>=0&&nBy<N&&nBx>=0&&nBx<N&&!runB[nBy][nBx]){
						runB[nBy][nBx]=1;
						if(cloth[nBy][nBx]==askedcol)ansnum--;
						cloth[nBy][nBx]=combine('B',cloth[nBy][nBx]);
						cB.push((pos){nBy,nBx});
						if(cloth[nBy][nBx]==askedcol)ansnum++;
					}
				}
			}
			for(int rr=0;rr<Rtimes;rr++){
				int cRy=cR.front()._y,cRx=cR.front()._x;
				cR.pop();
				for(int i=0;i<8;i++){
					int nRy=cRy+Y[i],nRx=cRx+X[i];
					if(nRy>=0&&nRy<N&&nRx>=0&&nRx<N&&!runR[nRy][nRx]){
						runR[nRy][nRx]=1;
						if(cloth[nRy][nRx]==askedcol)ansnum--;
						cloth[nRy][nRx]=combine('R',cloth[nRy][nRx]);
						cR.push((pos){nRy,nRx});
						if(cloth[nRy][nRx]==askedcol)ansnum++;
					}
				}
			}
			if(lastnum<ansnum)lastnum=ansnum;
			//print();
		}
		printf("%d\n",lastnum);
	}
}
int check(){
	int ch=0;
	for(int y=0;y<N;y++){
		for(int x=0;x<N;x++){
			if(cloth[y][x]==askedcol)ch++;
		}
	}
	return ch;
}
void print(){
	printf("\n");
	for(int y=0;y<N;y++){
		for(int x=0;x<N;x++){
			if(cloth[y][x]=='X')printf(" ");
			else printf("%c",cloth[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}
char combine(char _col1,char _col2){
	if(_col2=='X'||_col1==_col2)return _col1;
	switch(_col1){
		case 'Y':
			switch(_col2){
				case 'R':return 'O';
				case 'B':return 'G';
				case 'O':return 'O';
				case 'P':return 'D';
				case 'G':return 'G';
			}
		case 'B':
			switch(_col2){
				case 'R':return 'P';
				case 'Y':return 'G';
				case 'O':return 'D';
				case 'P':return 'P';
				case 'G':return 'G';
			}
		case 'R':
			switch(_col2){
				case 'Y':return 'O';
				case 'B':return 'P';
				case 'O':return 'O';
				case 'P':return 'P';
				case 'G':return 'D';
			}
	}
}
