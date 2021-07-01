// passed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxlen 258
typedef struct Node{
    char c;
    struct Node *left, *right;
} Node;

char expr[maxlen]={};
int pos;

Node *EXPR();
Node *FACTOR();
Node *createNode(char c){
    Node *tmp = (Node*) calloc(1, sizeof(Node));
    tmp->c = c;
    return tmp;
}
void output(Node *root){
    if(root == NULL) return;
    output(root->left);
    putchar(root->c);
    if(root->right != NULL && (root->right->c == '|' || root->right->c == '&')){
        putchar('(');
        output(root->right);
        putchar(')');
    } 
    else output(root->right);
}
void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

Node *EXPR(){
    Node *root, *right;
    right = FACTOR();
    if(pos < 0 || (expr[pos] != '|' && expr[pos] != '&')) return right;
    else root = createNode(expr[pos]);
    pos--;
    root->left = EXPR();
    root->right = right;
    return root;
}
Node *FACTOR(){
    Node *root;
    if(expr[pos] != ')') root = createNode(expr[pos]);
    else{
        pos--;
        root = EXPR();
    }
    pos--;
    return root;
}

int main(){
    scanf("%s", expr);
    pos = strlen(expr)-1;
    Node *root = EXPR();
    output(root);
    freeTree(root);
}