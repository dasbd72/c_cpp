// 12612.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char c;
    struct Node *r;
}Node;
Node *createNode(char c){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = c;
    return tmp;
}
Node *createList(char *S){
    Node *head, *curr = NULL;
    int Slen = strlen(S);
    curr = head = createNode(0);
    for(int i = 0; i < Slen; i++)
        curr = curr->r = createNode(S[i]);
    return head;
}
void printList(Node *head){
    head = head->r;
    while(head){
        putchar(head->c);
        head = head->r;
    }
    puts("");
}
int main(){
    char S[10005];
    int M, L, R, K, i;
    Node *head, *curr, *n1, *n2, *n3, *tmp;
    scanf("%s %d", S, &M);
    head = createList(S);
    while(M--){
        scanf("%d %d %d", &L, &R, &K);
        K %= (R-L+1);
        if(K == 0) continue;
        
        curr = head;
        for(i = 1; i < L; i++) curr = curr->r;
        n1 = curr;
        for(; i < R + 1 - K; i++) curr = curr->r;
        n2 = curr;
        for(; i <= R; i++) curr = curr->r;
        n3 = curr;

        tmp = n1->r;
        n1->r = n2->r;
        n2->r = n3->r;
        n3->r = tmp;
    }
    printList(head);
}