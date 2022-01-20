#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int gift[7]={},flag;
int boxnum;
//6*6=36 5*5=25 4*4=16 3*3=9
int main(){
	while(true){
		flag=0,boxnum=0;
		for(int i=1;i<=6;i++){
			scanf("%d",&gift[i]);
		}
		for(int i=1;i<=6;i++){
			if(gift[i]!=0)break;
			if(i==6)flag=1;
		}if(flag)break;
		//start
		boxnum+=gift[6];//6*6
		boxnum+=gift[5];//5*5
		boxnum+=gift[4];//4*4
		gift[1]-=gift[5]*11;
		gift[2]-=gift[4]*5;
		if(gift[1]>0&&gift[2]<0)gift[1]+=(gift[2]*4);
		int tmp,remain;
		if(gift[3]%4)tmp=gift[3]/4+1;//3*3
		else tmp=gift[3]/4;
		boxnum+=tmp;
		tmp=gift[3]%4;
		if(tmp==3){
			remain=9;
			for(int i=1;i<=1&&gift[2]>0;i++){
				gift[2]-=1;
				remain-=4;
			}
			for(int i=1;i<=remain&&gift[1]>0;i++)gift[1]-=1;
		}
		else if(tmp==2){
			remain=18;
			for(int i=1;i<=3&&gift[2]>0;i++){
				gift[2]-=1;
				remain-=4;
			}
			for(int i=1;i<=remain&&gift[1]>0;i++)gift[1]-=1;
		}
		else if(tmp==1){
			remain=27;
			for(int i=1;i<=5&&gift[2]>0;i++){
				gift[2]-=1;
				remain-=4;
			}
			for(int i=1;i<=remain&&gift[1]>0;i++)gift[1]-=1;
		}
		if(gift[2]>0){//2*2
			tmp=gift[2]%9?gift[2]/9+1:gift[2]/9;
			boxnum+=tmp;
			if(gift[2]%9)gift[1]-=(36-(gift[2]%9)*4);
		}
		if(gift[1]>0){//1*1
			tmp=gift[1]%36?gift[1]/36+1:gift[1]/36;
			boxnum+=tmp;
		}
		printf("%d\n",boxnum);
	}
	return 0;
}
