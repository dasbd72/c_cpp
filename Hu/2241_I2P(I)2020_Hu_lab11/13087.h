#include <stdlib.h>
#define SWAP(a,b,t) {t __tmp__ = a; a=b;b=__tmp__;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
Node* createNode(int data){
    Node* tmp = (Node*)calloc(1, sizeof(Node));
    tmp->data = data;
    return tmp;
}
Node* createList(int *a, int size){
    Node *head=NULL, *curr = NULL;
    for(int i = 0; i < size; i++){
        if(curr == NULL) head = curr = createNode(a[i]);
        else curr = curr->next = createNode(a[i]);
    }
    return head;
}
void push_front(Node** head, int val){
    Node *head2 = createNode(val);
    head2->next = *head;
    *head = head2;
}
void deleteElementByIdx(Node** head, int idx){
    Node *head2, *curr, *tofree;
    head2 = curr = createNode(0);
    curr->next = *head;
    for(int i = 0; i < idx && curr->next; i++) curr = curr->next;
    if(curr->next){
        tofree = curr->next;
        curr->next = curr->next->next;
        free(tofree);
    }
    *head = head2->next;
    free(head2);
}
Node* copyList(Node* head){
    Node *head2 = NULL, *curr = NULL;
    for(;head; head = head->next){
        if(curr == NULL) head2 = curr = createNode(head->data);
        else curr = curr->next = createNode(head->data);
    }
    return head2;
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *curr = *head, *n1 = NULL, *n2 = NULL;
    for(int i = 0; curr; i++, curr=curr->next){
        if(i == idx1) n1 = curr;
        if(i == idx2) n2 = curr;
    }
    if(n1 == NULL || n2 == NULL) return;
    SWAP(n1->data, n2->data, int);
}
void ReverseList(Node** head){
    Node *curr = *head, *prev = NULL, *tmp;
    while(curr){
        tmp = prev;
        prev = curr;
        curr = curr->next;
        prev->next = tmp;
    }
    *head = prev;
}
void ShiftListByK(Node** head, int k){
    Node *curr, *tmp, *end;
    int size = 0;
    for(curr = *head; curr; curr = curr->next) size++, end = curr;
    k %= size;
    if(k == 0) return;
    k = size - k;
    curr = *head;
    for(int i = 0; i < k; i++){
        tmp = curr;
        curr = curr->next;
    }
    tmp->next = NULL;
    end->next = *head;
    *head = curr;
}
