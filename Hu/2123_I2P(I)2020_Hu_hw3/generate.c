#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define A 100
#define B 100
int main()
{
	srand(time(NULL));
	printf("%d\n", A);
	for(int i = 0; i < A; i++)
	{
		printf("%d", rand()%10);
	}printf("\n");
	printf("%d\n", B);
	for(int i = 0; i < B; i++)
	{
		printf("%d", rand()%10);
	}printf("\n");
}