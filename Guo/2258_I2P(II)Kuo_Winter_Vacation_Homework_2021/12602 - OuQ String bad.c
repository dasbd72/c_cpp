// 12602.c
#include <stdio.h>
#include <stdlib.h>
#define ll long long
typedef struct Node{
    char c;
    int i, n;
    ll len;
    struct Node *next, *next2, *end;
} Node;
// create a node with char c and initialized
Node *createNode(char c){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->c = c;
    tmp->n = 1;
    return tmp;
}
// output from head's l to r
void printList(Node *head, ll l, ll r){
    Node *curr = head;
    int tmp;
    ll idx = 0;
    while(curr != head->end->next){
        if(idx >= l && idx <= r) putchar(curr->c);
        if(curr->end != NULL && (idx >= r || (idx < l && idx + curr->len - 1 <= l))){
            idx += curr->len - 1;
            curr = curr->end;
        }
        else{
            tmp = curr->i;
            curr->i = (curr->i + 1) % curr->n;
            if(tmp == 0) curr = curr->next;
            else if(tmp == 1) curr = curr->next2;
            idx++;
        }
    }
    puts("");
    head->end->i = 0;
}
// create list in this special method
Node *addList(Node *old){
    Node *head, *nodeO, *nodeu, *nodeQ;
    head = nodeO = createNode('O');
    nodeu = createNode('u');
    head->end = nodeQ = createNode('Q');
    
    nodeO->next = old;
    old->end->next = nodeu;
    nodeu->next = old;
    old->end->next2 = nodeQ;
    head->len = old->len*2 + 3;
    old->end->n = 2;

    return head;
}

int main(){
    // initialize
    Node *head = createNode('O'), *curr;
    head->next = createNode('u');
    head->end = head->next->next = createNode('Q');
    head->len = 3;
    // create the max list
    for(int i = 1; i < 50; i++) head = addList(head);
    
    int K, layer;
    ll L, R;
    while (scanf("%d %lld %lld", &K, &L, &R) != EOF){
        curr = head;
        layer = 50;
        while(layer-- > K) curr = curr->next; // go to the head of Sk
        printList(curr, L, R);
    }
}