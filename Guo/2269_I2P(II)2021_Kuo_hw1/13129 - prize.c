// passed
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int i;
    struct Node *prev, *next;
}Node;
int main(){
    Node *head, *curr, *tmp;
    int N, K, X;
    scanf("%d %d", &N, &K);
    scanf("%d", &X);
    head = curr = (Node*)malloc(sizeof(Node));
    curr->i = 1;
    for(int i = 2; i <= N; i++){
        tmp = (Node*)malloc(sizeof(Node));
        tmp->i = i;
        curr->next = tmp;
        tmp->prev = curr;
        curr = tmp;
    }
    curr->next = head;
    head->prev = curr;
    curr = head;
    while(K--){
        if(X % 2){
            while(--X) curr = curr->next;
        }else{
            while(--X) curr = curr->prev;
        }
        tmp = curr;
        if(K){
            scanf("%d", &X);
            if(X % 2) curr = curr->next;
            else curr = curr->prev; 
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        printf("%d\n", tmp->i);
        free(tmp);
    }
}