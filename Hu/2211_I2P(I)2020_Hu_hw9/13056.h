#include<stdlib.h>
#include<string.h>
#define MIN(a,b) (a < b ? a : b)
typedef struct {
	int num;
	char* name;
} Monkey;

Monkey* CreateMonkeyArray(int);
void FreeMonkeyArray(Monkey*, int);
void SetVal(Monkey*, int, int, char[]);
int Compare(Monkey*, int, int);
void Swap(Monkey*, int, int);

Monkey* CreateMonkeyArray(int len){
	Monkey* arr = (Monkey*)calloc(len, sizeof(Monkey));
	for(int i = 0; i < len; i++) arr[i].name = (char*)calloc(51, sizeof(char));
	return arr;
}
void FreeMonkeyArray(Monkey* arr, int len){
	for(int i = 0; i < len; i++) free(arr[i].name);
	free(arr);
}
void SetVal(Monkey* arr, int i, int num, char* name){
	arr[i].num = num;
	strcpy(arr[i].name, name);
}
int Compare(Monkey* arr, int a, int b){
	if(arr[a].num < arr[b].num) return 1;
	if(arr[a].num > arr[b].num) return 0;
	int len = MIN(strlen(arr[a].name), strlen(arr[b].name));
	for(int i = 0; i < len; i++){
		if(arr[a].name[i] < arr[b].name[i]) return 1;
		if(arr[a].name[i] > arr[b].name[i]) return 0;
	}
	return strlen(arr[a].name) < strlen(arr[b].name);
}
void Swap(Monkey* arr, int a, int b){
	int tnum = arr[a].num; char *tname = arr[a].name;
	arr[a].num = arr[b].num, arr[a].name = arr[b].name;
	arr[b].num = tnum, arr[b].name = tname;
}