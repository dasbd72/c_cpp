#include<stdio.h>
int main(){
	FILE *fin, *fout;
	fout = fopen("testfile.txt", "w+");
	fprintf(fout, "%d\n", 100);
	fclose(fout);
	return 0;
}