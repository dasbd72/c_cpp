#include<stdio.h>
#include<algorithm>
#include <functional>
#define MAXN 10000+5
using namespace std;
typedef pair <int,int> pii;
int N;
pii a[MAXN];
int sum,res;
int main(){
	while(scanf("%d",&N)&&N!=0){
		sum=0,res=-1;
		for(int iN=0;iN<N;iN++){
			scanf("%d %d",&a[iN].second,&a[iN].first);
		}
		sort(a,a+N,greater<pii>());
		for(int i=0;i<N;i++){
			res=max(res,sum + a[i].first + a[i].second);
			sum+=a[i].second;
		}
		printf("%d\n",res);
	}
}
