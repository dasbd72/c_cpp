#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char c;
    int re;
    struct Node *next[2], *end;
}Node;
Node *createNode(char c){
    Node* tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = c;
    tmp->re = 0;
    return tmp;
}
int main(){
    int N, SN, Q, T, A, B;
    char S[5];
    Node *head[100005]={};
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &SN);
        if(SN){
            Node *curr = NULL;
            for(int j = 0; j < SN; j++){
                scanf("%1s", S);
                if(curr == NULL){
                    head[i] = curr = createNode(S[0]);
                }
                else{
                    curr->next[0] = createNode(S[0]);
                    curr->next[0]->next[1] = curr;
                    curr = curr->next[0];
                }
                head[i]->end = curr;
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
                if(currB != NULL){
                    currA->end->next[currA->end->re%2] = currB;
                    currB->next[(currB->re+1)%2] = currA->end;
                    currA->end = currB->end;
                }
            }
        } else if(T == 2){
            scanf("%d %d", &A, &B);
            Node *currA = head[A], *currB = head[B];
            head[A] = NULL;
            if(currB == NULL) head[B] = currA;
            else if(currA != NULL){
                currB->end->next[currB->end->re%2] = currA;
                currA->next[(currA->re+1)%2] = currB->end;
                currB->end = currA->end;
            }
        } else if(T == 3){
            scanf("%d %d", &A, &B);
            Node *currA = head[A], *currB = head[B];
            head[A] = currB, head[B] = currA;
        } else if(T == 4){
            scanf("%d", &A);
            Node *tmp, *curr;
            curr = head[A];
            if(curr != NULL){
                curr->re++;
                curr->end->re++;
                head[A] = curr->end;
                head[A]->end = curr;
            }
        }
        puts("----------------");
        for(int i = 1; i <= N; i++){
            Node *curr = head[i];
            int d = 0;
            while(curr != NULL){
                putchar(curr->c);
                d = (d + curr->re)%2;
                curr = curr->next[1];
            }
            puts("");
        }
        puts("----------------");    
    }

    // puts("----------------");
    for(int i = 1; i <= N; i++){
        Node *curr = head[i];
        int d = 0;
        while(curr != NULL){
            putchar(curr->c);
            d = (d + curr->re)%2;
            curr = curr->next[d];
        }
        puts("");
    }
    // puts("----------------");
}