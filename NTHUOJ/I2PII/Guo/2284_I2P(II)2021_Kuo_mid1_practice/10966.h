// passed
#ifndef FUNCTION_H
#define FUNCTION_H
#include<stdlib.h>
#include<stdio.h>
#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode* EXPR(){
    BTNode *root, *right, *left;
    
    right = FACTOR();
    if(pos < 0 || (expr[pos] != '|' && expr[pos] != '&')) return right;
    else root = makeNode(expr[pos]);
    pos--;
    left = EXPR();
    root->left = left;
    root->right = right;
    return root;
}

BTNode* FACTOR(){
    BTNode *root;
    if(expr[pos] == ')'){
        pos--;
        root = EXPR();
    } 
    else root = makeNode(expr[pos]);
    pos--;
    return root;
}

BTNode* makeNode(char c){
    BTNode *tmp = (BTNode*)calloc(1, sizeof(BTNode));
    switch (c)
    {
    case 'A':
        tmp->data = ID_A;
        break;
    case 'B':
        tmp->data = ID_B;
        break;
    case 'C':
        tmp->data = ID_C;
        break;
    case 'D':
        tmp->data = ID_D;
        break;
    case '&':
        tmp->data = OP_AND;
        break;
    case '|':
        tmp->data = OP_OR;
        break;
    }
    return tmp;
}


#endif