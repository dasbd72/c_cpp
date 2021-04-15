// passed
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED 

#include<stdlib.h>
#include<stdio.h>

typedef struct _Tree_Node{
    int number;
    struct _Tree_Node* parent;
    struct _Tree_Node* left;
    struct _Tree_Node* right;
}Tree_Node;

Tree_Node* tree_head;

Tree_Node* createNode(int n){
    Tree_Node* tmp = (Tree_Node*)calloc(1, sizeof(Tree_Node));
    tmp->number = n;
    return tmp;
}
void add_node(int n){
    if(tree_head == NULL){
        tree_head = createNode(n); 
        return;
    }
    Tree_Node *curr = tree_head, *tmp = createNode(n);
    while(1){
        if(n >= curr->number) {
            if(curr->right == NULL){
                curr->right = tmp, tmp->parent = curr;
                break;
            }
            curr = curr->right;
        }
        else if(n < curr->number){
            if(curr->left == NULL){
                curr->left = tmp, tmp->parent = curr;
                break;
            }
            curr = curr->left;
        }
    }
}
void showtree(Tree_Node* treenow){
    if(treenow == NULL) return;
    showtree(treenow->left);
    printf("%d ", treenow->number);
    showtree(treenow->right);
}

#endif



