#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {int __tmp__ = a;a=b;b=__tmp__;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
Node* createList(int *a, int size){
    Node *start, *curr;
    for(int i = 0; i < size; i++){
        if(i == 0) start = curr = (Node*)calloc(1,sizeof(Node));
        else curr = curr->next = (Node*)calloc(1,sizeof(Node));
        curr->data = a[i];
    }
    return start;
}
void push_front(Node** head, int val){
    Node *curr = (Node*)calloc(1,sizeof(Node));
    curr->next = *head;
    curr->data = val;
    *head = curr;
}
void deleteElementByIdx(Node** head, int idx){
    Node *curr = *head, *tofree;
    if(idx == 0){
        tofree = *head;
        *head = (*head)->next;
    } else {
        idx--;
        while(idx-- && curr->next != NULL) curr = curr->next;
        if(curr->next == NULL) return;
        tofree = curr->next;
        curr->next = curr->next->next;
    }
    free(tofree);
}
Node* copyList(Node* head){
    Node *start = NULL, *curr = NULL;
    while(head != NULL){
        if(curr == NULL) start = curr = (Node*)calloc(1, sizeof(Node));
        else curr = curr->next = (Node*)calloc(1, sizeof(Node));
        curr->data = head->data;
        head = head->next;
    }
    return start;
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *m1, *m2, *curr = *head;
    if(idx1 > idx2) SWAP(idx1, idx2);
    for(int i = 0; curr != NULL && i <= idx2; i++, curr = curr->next){
        if(i == idx1) m1 = curr;
        else if(i == idx2) m2 = curr;
    }
    if(m1->data != m2->data) SWAP(m1->data, m2->data);
}
