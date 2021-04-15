// passed
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head;

Node* createNode(int i){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->number = i;
    return tmp;
}

Node* createList(int n){
    Node *first, *curr, *tmp;
    first = curr = createNode(1);
    for(int i = 2; i <= n; i++){
        tmp = createNode(i);
        curr->next = tmp;
        tmp->prev = curr;
        curr = tmp;
    }
    curr->next = first;
    first->prev = curr;
    return first;
}
void solveJosephus(int n, int m){
    int x;
    Node *curr = head, *tmp;
    scanf("%d", &x);
    for(int i = 0; i < m; i++){
        if(x % 2){
            x = x % (n-i) == 0 ? n-i : x % (n-i);
            while(--x > 0) curr = curr->next;
        } else {
            x = x % (n-i) == 0 ? n-i : x % (n-i);
            while(--x > 0) curr = curr->prev;
        }
        tmp = curr;
        if(i < m-1){
            scanf("%d", &x);
            if(x % 2) curr = curr->next;
            else curr = curr->prev;
        }
        printf("%d\n", tmp->number);
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
}

#endif
