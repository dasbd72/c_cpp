#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);
void printInfix(Node *root);
void freeTree(Node *root);

void printInfix(Node *root){
    if(root == NULL) return;
    printInfix(root->left);
    putchar(root->data);
    if(root->right != NULL && (root->right->data == '|' || root->right->data == '&')){
        putchar('(');
        printInfix(root->right);
        putchar(')');
    }
    else printInfix(root->right);
}

#endif