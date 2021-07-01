// passed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Card{
    int i;
    struct Card *next;

} Card;
Card *createCard(int i){
    Card *tmp = (Card*)calloc(1, sizeof(Card));
    tmp->i = i;
    return tmp;
}
int main(){
    int N, M, X, A, B;
    char S[5];
    Card *head, *end, *curr, *tmp, *tmpl, *tmpr, *tmpll, *tmprr;
    curr = head = createCard(0);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &X);
        curr = curr->next = createCard(X);
    }
    end = curr->next = createCard(0);
    
    while(M--){
        scanf("%s %d %d", S, &A, &B);
        curr = head;
        if(strcmp(S, "ADD") == 0){
            tmp = createCard(B);
            while(A--) curr = curr->next;
            tmp->next = curr->next;
            curr->next = tmp;
        }else if(strcmp(S, "CUT") == 0){
            if(A == 0) continue;
            for(int i = 0; curr != end; i++){
                if(i == A) tmpll = curr;
                if(i == A+B) tmpr = curr;
                curr = curr->next;
            }
            tmpl = tmpll->next;
            tmprr = tmpr->next;
            tmpr->next = head->next;
            head->next = tmpl;
            tmpll->next = tmprr;

        }
    }
    curr = head->next;
    while(curr != end){
        printf("%d\n", curr->i);
        curr = curr->next;
    }
}