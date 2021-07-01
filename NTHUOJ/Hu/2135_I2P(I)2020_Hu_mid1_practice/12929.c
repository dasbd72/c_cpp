#include<stdio.h>
int main()
{
	int info[2][5]={}; //month, day, hour, minute, second
	int pA = 0, pB = 1; // person one and person two
	for(int i = 0; i < 2; i++) scanf("%d/%d %d:%d:%d", &info[i][0], &info[i][1], &info[i][2], &info[i][3], &info[i][4]);
	for(int i = 0; i < 5; i++)
	{
		if(info[pA][i] > info[pB][i]) break;
		else if(info[pA][i] < info[pB][i])
		{
			pA = 1, pB = 0;
			break;
		}
	}
	//sec
	info[pA][4] -= info[pB][4];
	if(info[pA][4] < 0) info[pA][4] += 60, info[pA][3]--;
	//min
	info[pA][3] -= info[pB][3];
	if(info[pA][3] < 0) info[pA][3] += 60, info[pA][2]--;
	//hour
	info[pA][2] -= info[pB][2];
	if(info[pA][2] < 0) info[pA][2] += 24, info[pA][1]--;
	//day
	info[pA][1] -= info[pB][1];
	if(info[pA][1] < 0) info[pA][1] += 30, info[pA][0]--;
	//month
	info[pA][0] -= info[pB][0];

	printf("%d %d\n%02d:%02d:%02d\n", info[pA][0], info[pA][1], info[pA][2], info[pA][3], info[pA][4]);
	return 0;
}