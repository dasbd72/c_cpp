#include<stdio.h>
#include<string.h>
#include<stack>
char input[82]={};
int tmpx,tmpy,sodoku[9][9],boolchange[9][9],frontone[9][9][2];
int _check(int,int);
int _getans();
int main(){
while(scanf("%s",&input)&&input[0]!='e'){
	int i=0,ix,iy;
	tmpx=-1,tmpy=-1;
	memset(frontone,0,sizeof(frontone));
	memset(boolchange,0,sizeof(boolchange));
	memset(sodoku,0,sizeof(sodoku));
	for(ix=0;ix<9;ix++)for(iy=0;iy<9;iy++){
		if(input[i]!='0'&&input[i]!='.'){
			sodoku[ix][iy]=input[i]-'0';
			i++;
		}
		else{
			boolchange[ix][iy]=1;
			frontone[ix][iy][0]=tmpx;
			frontone[ix][iy][1]=tmpy;
			tmpx=ix;
			tmpy=iy;
			i++;
		}
	}
	
	if(_getans()==0)printf("No solution.\n");
	else{
		for(ix=0;ix<9;ix++){
			for(iy=0;iy<9;iy++){
				printf("%d",sodoku[ix][iy]);
			}
		}
		printf("\n");
	}
	
}}
int _getans(){
	int ix,iy,irun,tix,tiy;
	
	for(ix=0;ix<9;ix++)for(iy=0;iy<9;iy++){
		if(!boolchange[ix][iy])if(!_check(ix,iy)){
			 return 0;
		}
	}
	for(ix=0;ix<9;ix++)for(iy=0;iy<9;iy++){
		if(boolchange[ix][iy]){
			irun=0;
			while(irun==0){
				if(sodoku[ix][iy]==9){
					if(frontone[ix][iy][0]==-1)return 0;
					else{//traceback
						sodoku[ix][iy]=0;
						tix=frontone[ix][iy][0],tiy=frontone[ix][iy][1];
						ix=tix,iy=tiy;
					}
				}
				else{
					sodoku[ix][iy]++;
					irun=_check(ix,iy);
					if(irun==0&&sodoku[ix][iy]==9){
						if(frontone[ix][iy][0]==-1)return 0;
						else{//traceback
							sodoku[ix][iy]=0;
							tix=frontone[ix][iy][0],tiy=frontone[ix][iy][1];
							ix=tix,iy=tiy;
						}
					}
				}
			}
		}
	}
	return 1;
}
int _check(int _x,int _y){
	for(int ix=0;ix<9;ix++){
		if(ix!=_x&&sodoku[_x][_y]==sodoku[ix][_y])return 0;
	}
	for(int iy=0;iy<9;iy++){
		if(iy!=_y&&sodoku[_x][_y]==sodoku[_x][iy])return 0;
	}
	int bsx=(_x/3)*3,bsy=(_y/3)*3;
	for(int ix=bsx;ix<bsx+3;ix++)for(int iy=bsy;iy<bsy+3;iy++){
		if(ix!=_x&&iy!=_y&&sodoku[_x][_y]==sodoku[ix][iy])return 0;
	}
	return 1;
}
