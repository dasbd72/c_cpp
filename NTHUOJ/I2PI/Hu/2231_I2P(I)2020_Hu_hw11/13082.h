#include<stdlib.h>
#define SWAP(a,b) {int __tmp__ = a;a=b;b=__tmp__;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Merge_lists(Node*, Node*);
void sort_list(Node* head);
void print_list(Node* head);

Node* Merge_lists(Node* x, Node* y){
    Node *start = NULL, *curr = NULL;
    int op;
    sort_list(x);
    sort_list(y);
    while(x != NULL || y != NULL){
        if(curr == NULL) start = curr = (Node*)calloc(1, sizeof(Node));
        else{
            while(x && x->data == curr->data) x = x->next;
            while(y && y->data == curr->data) y = y->next;
            if(x == NULL && y == NULL) break;
            curr = curr->next = (Node*)calloc(1, sizeof(Node));
        }

        if(x != NULL && y != NULL) {
            if(x->data <= y->data) op = 1;
            else op = 2;
        }
        else if(x != NULL) op = 1;
        else if(y != NULL) op = 2;

        if(op == 1){
            curr->data = x->data;
            x = x->next;
        } else {
            curr->data = y->data;
            y = y->next;
        }
    }
    return start;
}
void sort_list(Node* head){
    for(Node* ny = head; ny != NULL; ny = ny->next)
        for(Node* nx = ny->next; nx != NULL; nx = nx->next)
            if(ny->data > nx->data) SWAP(ny->data, nx->data);
}
void print_list(Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    puts("");
}