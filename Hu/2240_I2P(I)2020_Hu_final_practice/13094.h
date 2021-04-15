#include<stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Partial_sort(Node* head, int x){
    Node *head2, *curr2, *curr, *prev, *tmp;
    head2 = curr2 = prev = (Node*)calloc(1, sizeof(Node)); // new head with empty data
    curr = curr2->next = head;
    while(curr != NULL){
        if(curr->data < x) { // move if is smaller than x
            tmp = curr; // save the current node
            curr = curr->next; // move curr to next
            prev->next = curr; // prev next point to the new curr
            tmp->next = curr2->next;
            if(curr2->next == curr) prev = tmp;
            curr2 = curr2->next = tmp;
        } else { // if no need to move, update the previous node and move curr forward
            prev = curr;
            curr = curr->next;
        }
    }
    curr2 = head2->next; // point to the real head
    free(head2); // free the empty node
    return curr2;
}

Node* Split_and_Swap(Node* head, int a, int b){
    Node *curr, *midleft, *midright, *end, *newhead;
    curr = end = head;
    // midleft = node(a+1), midright = node(b-1), end = node(n-1)
    // if a+1 = b then only need to attach the end to the head
    // else, u need to attach end to midleft, and attach midright to head
    for(int i = 0; curr != NULL; i++){
        end = curr;
        if(i == a && i+1 == b){
            newhead = curr->next;
            curr->next = NULL;
            curr = newhead;
        } else if(i == a){
            midleft = curr->next;
            curr->next = NULL;
            curr = midleft;
        } else if(i+1 == b){
            midright = curr;
            newhead = curr->next;
            curr = curr->next;
        } else curr = curr->next;
    }
    if(a+1 != b){
        end->next = midleft;
        midright->next = head;
    } else {
        end->next = head;
    }
    return newhead;
}
