// EXPR:(EXPR op XFUNC) or XFUNC, op:+ -
// XFUNC:(XFUNC op ID) or ID, op:* /
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Node{
    int num;
    char op;
    struct Node *left, *right;
}Node;
char expr[100];
int pos;

Node *EXPR();
Node *FACTOR();
Node *XFUNC();
Node *makeNode(){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    if(isdigit(expr[pos])){
        for(int i = pos-1; i >= 0 && isdigit(expr[i]); i--) pos--;
        sscanf(expr+pos, "%d", &tmp->num);
    }
    else tmp->op = expr[pos];
    return tmp;
}
Node *EXPR(){
    Node *right, *root;
    right = XFUNC();
    if(pos <= 0) return right;
    pos--;
    root = makeNode();
    root->right = right;
    pos--;
    root->left = EXPR();
    return root;
}
Node *XFUNC(){
    Node *right, *root;
    right = makeNode();
    if(pos <= 0 || expr[pos-1] == '+' || expr[pos-1] == '-') return right;
    pos--;
    root = makeNode();
    root->right = right;
    pos--;
    root->left = XFUNC();
    return root;
}
void printPrefix(Node* root){
    if(root == NULL) return;
    if(root->num) printf("%d ", root->num);
    else printf("%c ", root->op);
    printPrefix(root->left);
    printPrefix(root->right);
}
int main(){
    Node *root = NULL;
    while(scanf("%s", expr)!=EOF){
        pos = strlen(expr)-1;
        root = EXPR();
        printPrefix(root);
        puts("");
    }
}