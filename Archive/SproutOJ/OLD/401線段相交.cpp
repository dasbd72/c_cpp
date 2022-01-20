#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<long long,long long> Pt;

int way(Pt& m,Pt& n,Pt& o){
	Pt a, b;
	a = make_pair(n.X-m.X, n.Y-m.Y);
	b = make_pair(o.X-n.X, o.X-n.X);
	long long cross = a.X*b.Y - a.Y*b.X;
	long long dot = a.X*b.X + a.Y*b.Y;
	long long sqcos = (dot==0) ? 0 : (dot*dot)/((a.X*a.X + a.Y*a.Y) * (b.X*b.X + b.Y*b.Y));
	if(cross > 0)return -1;
	else if(cross < 0)return 1;
	else if(dot < 0 && sqcos == 1)return 0;
}
int main() {
	int T;cin >> T;
	while(T--){
		Pt P1,P2,Q1,Q2,P,Q;
		cin >> P1.X >> P1.Y >> P2.X >> P2.Y 
				>> Q1.X >> Q1.Y >> Q2.X >> Q2.Y;
		if(P1.X > P2.X){
			int tmpx = P1.X, tmpy = P1.Y;
			P1.X = P2.X, P2.X = tmpx;
			P1.Y = P2.Y, P2.Y = tmpy;
		}
		if(Q1.X > Q2.X){
			int tmpx = Q1.X, tmpy = Q1.Y;
			Q1.X = Q2.X, Q2.X = tmpx;
			Q1.Y = Q2.Y, Q2.Y = tmpy;
		}
		cout << way(P1,P2,Q1) << ' ' << way(P1,P2,Q2) <<endl;
		if(way(P1,P2,Q1) * way(P1,P2,Q2) == -1){
			
		}
		else if(way(P1,P2,Q1)==0 && way(P1,P2,Q2)==0){
			
		}
		else printf("No\n");
	}
	return 0;
}

