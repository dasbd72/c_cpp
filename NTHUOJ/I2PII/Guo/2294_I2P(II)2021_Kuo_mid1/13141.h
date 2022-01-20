#ifndef FUNCTION_H
#define FUNCTION_H
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
int all_operation[300009];

typedef struct _Node{
    struct _Node *prev;
    struct _Node *next;
    int val;
    int tag;
} Node;
typedef struct OpTagK{
    int op, tag, k;
} OpTagK;

Node *head;
int sz, tag;
OpTagK arr[300005];
int arri;

Node *createNode(int val){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->val = val;
    tmp->tag = tag;
    return tmp;
}
void push(int x){
    static Node *endN = NULL;
    Node *tmp = createNode(x);
    if(endN == NULL || head == NULL) head = endN = tmp;
    else tmp->prev = endN, endN = endN->next = tmp;
    sz++;
}
void pop(){
    if(head == NULL) return;
    static Node *midN = NULL;
    static int mididx = 1;
    Node *tofree;
    int hfsz = (sz+1)/2;
    if(midN == NULL) midN = head;
    if(mididx < hfsz) while(mididx < hfsz) mididx++, midN = midN->next;
    else if(mididx > hfsz) while(mididx > hfsz) mididx--, midN = midN->prev;
    
    tofree = midN;
    if(sz == 1) head = midN = NULL;
    else if(sz == 2) head = midN = head->next, head->prev = NULL;
    else{
        if(sz % 2) midN = midN->prev, mididx--;
        else midN = midN->next;

        tofree->prev->next = tofree->next;
        tofree->next->prev = tofree->prev;
    }
    free(tofree);
    sz--;
}
void programming_tanoshi(int k){
    if(k == 1 || sz == 0) return;
    tag++;
    arr[arri] = (OpTagK){
        .op = 1,
        .tag = tag,
        .k = k
    };
    arri++;
}
void IP2_sugoi(){
    if(sz == 0) return;
    tag++;
    arr[arri] = (OpTagK){
        .op = 2,
        .tag = tag
    };
    arri++;
}
void KuoYangTeTe(){
    Node *curr, *newHead = head;
    int contOne;
    for(int i = 0; i < arri; i++){
        curr = newHead;
        contOne = 1;
        while(curr != NULL){
            if(curr->val == 1){
                if(contOne) newHead = curr;
                curr = curr->next;
                continue;
            }
            contOne = 0;
            if(curr->tag < arr[i].tag){
                if(arr[i].op == 1) curr->val = ceil((double)curr->val / arr[i].k );
                else curr->val = floor(sqrt( (double)curr->val));
            }
            else break;
            curr = curr->next;
        }
    }
}

#endif
