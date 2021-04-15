// pass
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node Node;
struct Node{
    int num;
    Node *next;
};

Node *curr;
int size;

Node *createnode(int,Node*);
void insert(int,int);
void erase(int);
void move(int);
void show();

int main(){
    int x, q;
    char buf[10];
    scanf("%d %d", &x, &q);
    curr = createnode(x, curr);
    size = 1;
    while(q--){
        scanf("%s", buf);
        if(!strcmp(buf, "insert")) {
            int val1, val2;
            scanf("%d %d", &val1, &val2);
            insert(val1, val2);
        } else if(!strcmp(buf, "erase")) {
            int val;
            scanf("%d", &val);
            erase(val);
        } else if(!strcmp(buf, "move")) {
            int value;
            scanf("%d", &value);
            move(value);
        } else if(!strcmp(buf, "show")) {
            show();
        }
    }
}

Node *createnode(int num, Node* next){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->num = num;
    tmp->next = next == NULL ? tmp : next;
    return tmp;
}
void insert(int val1, int val2){
    size += val2;
    while(val2--) 
        curr->next = createnode(val1, curr->next);
}
void erase(int val){
    size -= val;
    Node *tofree;
    while(val-- && curr){
        tofree = curr->next;
        curr->next = curr->next->next;
        free(tofree);
    }
}
void move(int value){
    value %= size;
    while(value--)
        curr = curr->next; 
}
void show(){
    Node *cursor = curr;
    do{
        printf("%d%c", cursor->num, cursor->next == curr ? '\n' : ' ');
        cursor = cursor->next;
    }while(cursor != curr);
}