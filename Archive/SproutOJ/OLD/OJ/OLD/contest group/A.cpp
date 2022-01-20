#include<algorithm>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
string Y[14];
int yy[5][14]; // 0 m p s z
void print();
int turn(char x){
	if(x == 'm')return 1;
	if(x == 'p')return 2;
	if(x == 's')return 3;
	if(x == 'z')return 4;
}
int main(){
	int N; cin >> N;
	while(N--){
		memset(yy,0,sizeof(yy));
		for(int i = 1; i < 14; i++) {
			cin >> Y[i];
			yy[ turn(Y[i][1]) ][ Y[i][0] ]++;
		}
	}
	return 0;
}
void print(){
	for(int i = 1; i < 14; i++){
		cout << Y[i];
		if(i == 13) cout << '\n';
		else cout << ' ';
	}
}
//goal 3 3 3 3 1 or 3 3 3 2 2
