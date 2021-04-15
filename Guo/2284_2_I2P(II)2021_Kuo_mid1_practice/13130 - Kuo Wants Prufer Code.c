#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int idx;
    struct Node *next;
}Node;

Node *makeNode(int idx){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->idx = idx;
    return tmp;
}
void pushNode(Node *root, int idx){
    Node *tmp = makeNode(idx);
    tmp->next = root->next;
    root->next = tmp;
}
void popNode(Node *root, int idx){
    while(root->next->idx != idx){
        root = root->next;
    }
    Node *tofree = root->next;
    root->next = tofree->next;
    free(tofree);
}
int main(){
    int N, V, U, cnt[5005]={};
    Node *head[5005];
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        head[i] = makeNode(i);
        head[i]->next = head[i];
    }
    for(int i = 1; i < N; i++){
        scanf("%d %d", &V, &U);
        cnt[V]++, cnt[U]++;
        pushNode(head[V], U);
        pushNode(head[U], V);
    }
    for(int  i = 1; i <= N-2; i++){
        int idx = 1, prufer;
        while(cnt[idx] != 1) idx++;
        prufer = head[idx]->next->idx;
        cnt[idx]--, cnt[prufer]--;
        popNode(head[idx], prufer);
        popNode(head[prufer], idx);
        printf("%d ", prufer);
    }
    puts("");
}