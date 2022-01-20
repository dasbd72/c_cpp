#include<stdio.h>
#include<string.h>
int main(){
    char s1[1000005]={}, inp[10];
    char s2[1000005]={};
    int i = 1, wrong = 0, correct = 1;
    fgets(s1+1, 500005, stdin);
    while(fgets(inp, 5, stdin) != NULL){
        if(inp[0] == '\\'){
            if(s1[i-1] != s2[i-1]) wrong--, s2[i-1] = 0;
            i = i == 1 ? 1 : i-1;
        }
        else{
            s2[i] = inp[0];
            if(s1[i] != s2[i]) wrong++;
            i++;
        }
        if(wrong) puts("0");
        else puts("1");
    }
    for(int j = 1; s1[j] != '\n'; j++) if(s1[j] != s2[j]) correct = 0;
    printf("%s\n", correct && !wrong ? "Correct" : "Incorrect");
}