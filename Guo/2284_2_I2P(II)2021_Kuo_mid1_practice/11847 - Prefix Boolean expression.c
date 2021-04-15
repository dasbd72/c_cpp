#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    char key;
    struct Node *left;
    struct Node *right;
} Node;
char expr[40]; 
int pos;
bool keyIsOp(char key){
    if(key == '|' || key == '&') return true;
    return false;
}
Node *makeNode(char key){
    Node *tmp = (Node*) calloc(1, sizeof(Node));
    tmp->key = key;
    return tmp;
}
Node *parse(){
    Node *root = makeNode(expr[pos++]);
    if(!keyIsOp(root->key)) return root;
    root->left = parse();
    root->right = parse();
    return root;
}
bool getAns(Node *root, int set){
    if(!keyIsOp(root->key)) {
        if(root->key == 'A') return set & (1 << 3);
        else if(root->key == 'B') return set & (1 << 2);
        else if(root->key == 'C') return set & (1 << 1);
        else if(root->key == 'D') return set & (1 << 0);
    }
    if(root->key == '&') return getAns(root->left, set) && getAns(root->right, set);
    else if(root->key == '|') return getAns(root->left, set) || getAns(root->right, set);
}
int main(){
    Node *root;
    scanf("%s", expr);
    root = parse();
    for(int i = 0; i < 16; i++){
        for(int b = 3; b >= 0; b--){
            if(i & (1<<b)) printf("1 ");
            else printf("0 ");
        }
        printf("%d\n", getAns(root, i));
    }
}