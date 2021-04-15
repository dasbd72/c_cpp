#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAXLEN 256
typedef struct Node{
    char key;
    struct Node *lnode;
    struct Node *rnode;
} Node;
char expr[MAXLEN];
int pos;

Node *EXPR();
Node *FACTOR();
bool keyIsOp(char key){
    if(key == '|' || key == '&') return true;
    return false;
}
Node *makeNode(char key){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->key = key;
    return tmp;
}
Node *EXPR(){
    Node *root, *right;
    right = FACTOR();
    if(pos <= 0 || !keyIsOp(expr[pos-1])) return right;
    pos--;
    root = makeNode(expr[pos]);
    root->rnode = right;
    pos--;
    root->lnode = EXPR();
    return root;
}
Node *FACTOR(){
    Node *root;
    if(expr[pos] == ')'){
        pos--;
        root = EXPR();
        pos--;
    } else {
        root = makeNode(expr[pos]);
    }
    return root;
}
void printInfix(Node *root){
    if(!root) return;
    printInfix(root->lnode);
    putchar(root->key);
    if(root->rnode && keyIsOp(root->rnode->key)){
        putchar('(');
        printInfix(root->rnode);
        putchar(')');
    } 
    else printInfix(root->rnode);
}
void freeTree(Node *root){
    if(!root) return;
    freeTree(root->lnode);
    freeTree(root->rnode);
    free(root);
}
int main(){
    Node *root;
    scanf("%s", expr);
    pos = strlen(expr) - 1;
    root = EXPR();
    printInfix(root);
    freeTree(root);
    return 0;
}