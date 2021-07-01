#include<algorithm>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c;
	for(a=0;a<5;a++)for(b=0;b<8;b++)for(c=0;c<14;c++)if(a*3+b*2+c*1 == 13)cout << a<<' '<<b<<' '<<c<<'\n';
	return 0;
}
/*
0 0 13
0 1 11
0 2 9
0 3 7
0 4 5
0 5 3
0 6 1
1 0 10
1 1 8
1 2 6
1 3 4
1 4 2
1 5 0
2 0 7
2 1 5
2 2 3
2 3 1
3 0 4
3 1 2
3 2 0
4 0 1
*/
