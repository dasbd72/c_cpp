// AC
#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000006

typedef struct Node
{
    int key;
    struct Node *ltree;
    struct Node *rtree;
    struct Node *parent;
} Node ;
Node *createNode(int key){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->key = key;
    return tmp;
}
// build a binary search tree with given pre-order traversal
// return pointer to root
Node *buildBST(int n, int *preOrder){
    Node *head, *curr = NULL, *tmp, *root;
    for(int i = 0; i < n; i++){
        tmp = createNode(preOrder[i]);
        if(curr == NULL) head = curr = tmp;
        else if(tmp->key < curr->key){
            tmp->parent = curr;
            curr = curr->ltree = tmp;
        }
        else{
            root = curr;
            while(curr->parent != NULL && tmp->key > curr->parent->key){
                curr = curr->parent;
                if(curr->key > root->key) root = curr;
            }
            tmp->parent = root;
            curr = root->rtree = tmp;
        }
    }
    return head;
}

// print the in-order traversal of a given tree
// it is suggested to implement using recursion
void printInOrder(Node *ptr){
    if(ptr == NULL) return;
    printInOrder(ptr->ltree);
    printf("%d ", ptr->key);
    printInOrder(ptr->rtree);
}

// print the post-order traversal of a given tree
// it is suggested to implement using recursion
void printPostOrder(Node *ptr){
    if(ptr == NULL) return;
    printPostOrder(ptr->ltree);
    printPostOrder(ptr->rtree);
    printf("%d ", ptr->key);
}

// delete the binary search tree in case of memory leak
// it is suggested to implement using recursion
void freeTree(Node *ptr){
    if(ptr == NULL) return;
    freeTree(ptr->ltree);
    freeTree(ptr->rtree);
    free(ptr);
}

#endif // FUNCTION_H_
