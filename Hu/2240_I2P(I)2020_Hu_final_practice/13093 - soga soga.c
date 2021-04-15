#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int i;
    struct Node *l, *r;
} Node;

Node *start, *curr, *mid;
int N, Q, T, dir;

Node *create_node(int i);

int main(){
    scanf("%d", &N);
    start = curr = create_node(-1); // create empty start block
    for(int i = 1, a; i <= N; i++){
        scanf("%d", &a);
        curr->r = create_node(a);
        curr->r->l = curr;
        curr = curr->r;
    }
    curr->r = create_node(-1); // create empty end block
    curr = mid = start->r; // point to the first block
    for(int i = 1; i < (N%2 ? N/2+1 : N/2); i++) mid = mid->r; // create mid block

    for(scanf("%d", &Q); Q--;){
        scanf("%d", &T);
        if(T == 1) {
            scanf("%d", &dir);
            if(dir == -1) curr = curr->l;
            else if(dir == 1) curr = curr->r;
        } else if(T == 2) {
            printf("%d\n", curr->i);
        } else if(T == 3) {
            Node *tmp = mid;
            mid = N % 2 ? mid->l : mid->r;
            if(curr == tmp) curr = curr->r;
            tmp->l->r = tmp->r;
            tmp->r->l = tmp->l;
            free(tmp);
            N--;
        }
    }
}
Node *create_node(int i){
    Node *create_node_tmp = (Node*)calloc(1, sizeof(Node));
    create_node_tmp->i = i;
    return create_node_tmp;
}