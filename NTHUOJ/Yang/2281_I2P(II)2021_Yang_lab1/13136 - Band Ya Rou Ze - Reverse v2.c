#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char c;
    int d;
    struct Node *next[2], *end;
}Node;
Node *createNode(char c){
    Node* tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = c;
    tmp->d = 0;
    return tmp;
}
void reverse(Node **head){
    Node *tmp, *curr;
    tmp = curr = *head;
    if(curr != NULL){
        while(1){
            if(curr->next[curr->d] == NULL){
                curr->d ^= 1;
                curr->end = tmp;
                *head = curr;
                break;
            }
            curr->d ^= 1;
            curr = curr->next[curr->d^1];
        }
    }
}
int main(){
    int N, SN, Q, T, A, B;
    int reN[100005]={};
    char S[5];
    Node *head[100005]={};
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &SN);
        if(SN){
            Node *curr = NULL;
            for(int j = 0; j < SN; j++){
                scanf("%1s", S);
                if(curr == NULL) head[i] = curr = createNode(S[0]);
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
            if(reN[A]) reverse(&head[A]);
            if(reN[B]) reverse(&head[B]);
            reN[A] = reN[B] = 0;
            Node *currA = head[A], *currB = head[B];
            if(currA != NULL){
                head[B] = currA;
                head[A] = NULL;
                if(currB != NULL){
                    currA->end->next[currA->end->d] = currB;
                    currB->next[currB->d^1] = currA->end;
                    currA->end = currB->end;
                }
            }
        } else if(T == 2){
            scanf("%d %d", &A, &B);
            if(reN[A]) reverse(&head[A]);
            if(reN[B]) reverse(&head[B]);
            reN[A] = reN[B] = 0;
            Node *currA = head[A], *currB = head[B];
            head[A] = NULL;
            if(currB == NULL) head[B] = currA;
            else if(currA != NULL){
                currB->end->next[currB->end->d] = currA;
                currA->next[currA->d^1] = currB->end;
                currB->end = currA->end;
            }
        } else if(T == 3){
            scanf("%d %d", &A, &B);
            if(reN[A] != reN[B]) reN[A]^=1, reN[B]^=1;
            Node *currA = head[A], *currB = head[B];
            head[A] = currB, head[B] = currA;
        } else if(T == 4){
            scanf("%d", &A);
            reN[A]^=1;
        }
        // puts("----------------");
        // for(int i = 1; i <= N; i++){
        //     Node *curr = head[i];
        //     while(curr != NULL){
        //         putchar(curr->c);
        //         curr = curr->next[curr->d];
        //     }
        //     puts("");
        // }
        // puts("----------------");    
    }

    // puts("----------------");
    for(int i = 1; i <= N; i++){
        if(reN[i]) reverse(&head[i]);
        Node *curr = head[i];
        while(curr != NULL){
            putchar(curr->c);
            curr = curr->next[curr->d];
        }
        puts("");
    }
    // puts("----------------");
}