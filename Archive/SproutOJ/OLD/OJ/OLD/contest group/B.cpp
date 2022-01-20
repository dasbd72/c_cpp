#include<algorithm>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int A, B, W;
	cin >> A >> B >> W;
	int x,y,a,b;//a:winner b:loser
	if(W==1)x = 1, y = 2, a = A, b = B;
	else    x = 2, y = 1, a = B, b = A;
	
	if( (a-b)>33 || (b-a)>7 || a<22 ){
		cout << "-1\n";
		return 0;
	}
	int ca = 0, cb = 0;
	if(a-b > 4 && a >= 22){
		ca = 0, cb = 0;
		while(ca < 11 && ca-cb < 2 && cb < 11){
			for(int i = 0; i < 10; i++){
				cout << x << ' ';
				a--;
				ca++;
			}
			for(int i = 0; i < 10 && b; i++){
				cout << y << ' ';
				b--;
				cb++;
			}
			cout << x << '\n';
			a--;
			ca++;
		}
		ca = 0, cb = 0;
		while(ca < 11 && ca-cb < 2 && cb < 11){
			while(b){
				cout << y << ' ';
				b--;
				cb++;
			}
			while(a-1){
				cout << x << ' ';
				a--;
				ca++;
			}
			cout << x << '\n';
			a--;
			ca++;
		}
	}
	else{
		for(int i = 0; i < 10; i++) {
			cout << y << ' ';
			b--;
		}
		cout << y << '\n';
		b--;
		ca = 0, cb = 0;
		while(ca < 11 && ca-cb < 2 && cb < 11){
			for(int i = 0; i < 10; i++){
				cout << x << ' ';
				a--;
				ca++;
			}
			for(int i = 0; i < 10 && b; i++){
				cout << y << ' ';
				b--;
				cb++;
			}
			cout << x << '\n';
			a--;
			ca++;
		}
		ca = 0, cb = 0;
		while(ca < 11 && ca-cb < 2 && cb < 11){
			while(b){
				cout << y << ' ';
				b--;
				cb++;
			}
			while(a-1){
				cout << x << ' ';
				a--;
				ca++;
			}
			cout << x << '\n';
			a--;
			ca++;
		}
	}
	
	return 0;
}

