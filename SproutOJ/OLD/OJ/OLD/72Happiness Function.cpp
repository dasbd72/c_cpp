#include<stdio.h>
int T,n;
double a[10],b[10],c[10];
double S(double time);
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
		
		double f1=0,f2,f3,f4=300;
		for(int i=0;i<100;i++){
			f2=f4/3+(f1*2)/3;
			f3=(f4*2)/3+f1/3;
			if(S(f2)>S(f3))f1=f2;
			else if(S(f3)>S(f2))f4=f3;
			else f1=f2,f4=f3;
		}
		printf("%.5lf\n",S(f1));
	}
}
double S(double time){
	double max=0;
	for(int i=0;i<n;i++)if(a[i]*(time-b[i])*(time-b[i])+c[i]>max)
		max=a[i]*(time-b[i])*(time-b[i])+c[i];
	return max;
}
