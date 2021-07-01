// 12395.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ll long long
int x, y, z;
typedef struct Node
{
    char c;
    int num;
    struct Node *l, *r;
}Node;
int numlen(int num){
    int len = 0;
    while(num){
        num /= 10;
        len++;
    }
    return len;
}
Node *createNode(char c){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = c;
    return tmp;
}
Node *buildtree(char **exp){
    Node *tmp = createNode(**exp);
    if(isdigit(**exp)){
        tmp->num = atoi(*exp);
        (*exp) += numlen(tmp->num) + 1;
    }
    else{
        if(**exp == 'x') tmp->num = x;
        else if(**exp == 'y') tmp->num = y;
        else if(**exp == 'z') tmp->num = z;
        (*exp)+=2;
    }
    if(tmp->c == '+' || tmp->c == '-' || tmp->c == '*' || tmp->c == '/'){
        tmp->l = buildtree(exp);
        tmp->r = buildtree(exp);
    }
    return tmp;
}
int anstree(Node *root){
    if(root->num){
        if(isdigit(root->c)) printf("%d", root->num);
        else putchar(root->c);
        return root->num;
    }
    int lnum, rnum;
    if(root->l) lnum = anstree(root->l);
    putchar(root->c);
    if(root->r) rnum = anstree(root->r);

    if(root->c == '+') return lnum + rnum;
    if(root->c == '-') return lnum - rnum;
    if(root->c == '*') return lnum * rnum;
    if(root->c == '/') return lnum / rnum;
}
int main(){
    char *expression = (char*)malloc(300*sizeof(char)), *tofree;
    Node *root;
    gets(expression);
    scanf("%d %d %d", &x, &y, &z);
    tofree = expression;
    root = buildtree(&expression);
    printf("\n%d\n", anstree(root));
    free(tofree);
}