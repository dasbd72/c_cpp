//pass
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n){
    Node *head , *curr = NULL;
    for(int i = 1; i <= n; i++){
        if(curr == NULL) head = curr = (Node*)malloc(sizeof(Node));
        else curr = curr->next = (Node*)malloc(sizeof(Node));
        curr->number = i;
    }
    curr->next = head;
    return head;
}
void freeList(Node* head){
    if(head == NULL) return;
    Node *tofree, *curr = head->next;
    head->next = NULL;
    while(curr != NULL){
        tofree = curr;
        curr = curr->next;
        free(tofree);
    }
}
int solveJosephus(Node **head, int step){
    Node *tofree, *curr = (*head);
    int N = 1;
    while(curr->next != *head){
        curr = curr->next;
        N++;
    }
    (*head) = curr;
    for(int i = N; (*head)->next != (*head); i--){
        for(int j = step % i == 0 ? i : step % i; j > 1; j--) (*head) = (*head)->next;
        tofree = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(tofree);
    }
    return (*head)->number;
}

#endif
