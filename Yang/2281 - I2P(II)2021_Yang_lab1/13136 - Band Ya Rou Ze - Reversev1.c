#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char c;
    int d;
    struct Node *next;
}Node;
Node *createNode(char c){
    Node* tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = c;
    return tmp;
}
int main(){
    int N, SN, Q, T, A, B;
    char S[1000005];
    Node *head[100005]={};
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &SN);
        if(SN){
            Node *curr = NULL;
            
            for(int j = 0; j < SN; j++){
                scanf("%1s", S);
                if(curr == NULL) head[i] = curr = createNode(S[0]);
                else curr = curr->next = createNode(S[0]);
            }
        }
    }
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &T);
        if(T == 1){
            scanf("%d %d", &A, &B);
            Node *currA = head[A], *currB = head[B];
            if(currA != NULL){
                head[B] = currA;
                head[A] = NULL;
                while(currA->next != NULL) currA = currA->next;
                currA->next = currB;
            }
        } else if(T == 2){
            scanf("%d %d", &A, &B);
            Node *currA = head[A], *currB = head[B];
            head[A] = NULL;
            if(currB == NULL)
                head[B] = currA;
            else{
                while(currB->next != NULL) currB = currB->next;
                currB->next = currA;
            }
        } else if(T == 3){
            scanf("%d %d", &A, &B);
            Node *currA = head[A], *currB = head[B];
            head[A] = currB;
            head[B] = currA;
        } else if(T == 4){
            scanf("%d", &A);
            Node *prev = NULL, *curr = head[A], *tmp;
            if(curr != NULL){
                while(curr->next != NULL){
                    tmp = curr;
                    curr = curr->next;
                    tmp->next = prev;
                    prev = tmp;
                }
                curr->next = prev;
                head[A] = curr;
            }
        }
        
    }
    // puts("----------------");
    for(int i = 1; i <= N; i++){
        Node *curr = head[i];
        while(curr != NULL){
            putchar(curr->c);
            curr = curr->next;
        }
        puts("");
    }
    // puts("----------------");
}