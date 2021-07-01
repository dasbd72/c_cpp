#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
struct Line{
	int index;
	Line *r;
}*ptr[350][2];//head&tail

int cd(int nu,int de){//ceiling devide
	if(nu==0)return 0;
	int frac = (nu%de==0) ? nu/de : nu/de+1;
	return frac;
}
int main() {
	int N, M, BK, BL, amount;
	cin >> N >> M;
	BL = 316, amount = N;
	//初始化
	for(int i = 1;i <= cd(N+M, BL);i++){
		ptr[i][0] = new Line();
		ptr[i][0]->index = -1;
		ptr[i][0]->r = NULL;
		ptr[i][1] = ptr[i][0];
	}
	//輸入 
	for(int x, i = 1;i <= N;i++){
		cin >> x;
		ptr[cd(i,BL)][1]->r = new Line();
		ptr[cd(i,BL)][1] = ptr[cd(i,BL)][1]->r;
		ptr[cd(i,BL)][1]->index = x;
	}
	//指令
	while(M--){
		char command[6];int coor, x;
		cin >> command >> coor;
		Line *node = ptr[cd(coor, BL)][0];
		int tmp = coor-(cd(coor, BL)-1)*BL;
		for(int i = 1;i < tmp;i++)node = node->r;
		if(command[0]=='A'){
			amount++;
			cin >> x;
			Line *insert = new Line();
			insert->index = x;
			insert->r = node->r;
			node->r = insert;
		}
		else if(command[0]=='L'){
			
			amount--;
		}
		else printf("%d\n",node->index);
	}
}

