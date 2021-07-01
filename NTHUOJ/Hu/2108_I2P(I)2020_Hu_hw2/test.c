#include<stdio.h>
int main(){
	int a[10]={};
	/*
	1 2 3 4 5 6 7 8 9 
	1 1 2 0 0 0 0 0 0
	*/
	int x;
	while(scanf("%d", &x)){
		if(x == 0) break;
		a[x]++;
	}
	for(int i = 0; i < 10; i ++){
		printf("%d ", a[i]);
	}
}
