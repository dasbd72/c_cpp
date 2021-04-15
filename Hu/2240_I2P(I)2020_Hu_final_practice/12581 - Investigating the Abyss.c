#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int i, n;
    struct Node **next;
}Node;
int N, X[100001], Y[100001], cnt[100001];
Node *ptr[100001];
int pick(int, int);
int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        scanf("%d %d", X+i, Y+i);
        cnt[X[i]]++;
    }
    for(int i = 1; i <= N; i++){
        ptr[i] = (Node*)calloc(1, sizeof(Node));
        ptr[i]->i = i;
        ptr[i]->next = (Node**)calloc(cnt[i], sizeof(Node*));
    }
    for(int i = 1; i < N; i++)
        ptr[X[i]]->next[ptr[X[i]]->n++] = ptr[Y[i]];
    for(int i = 1; i <= N; i++)
        printf("%d%c", pick(i, 0)-1, i == N ? '\n' : ' ');
}
int pick(int idx, int last){
    int cnt = 1;
    for(int i = 0; i < ptr[idx]->n; i++){
        if(ptr[idx]->next[i]->i == last) continue;
        cnt += pick(ptr[idx]->next[i]->i, idx);
    }
    return cnt;
}