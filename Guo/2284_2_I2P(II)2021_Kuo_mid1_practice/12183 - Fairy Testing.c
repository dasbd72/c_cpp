#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int id;
    char op;
    bool status;
    struct Node *left, *right, *parent;
}Node;
Node *var[100005];
Node *parse(){
    char C[2];
    int X;
    Node *root;

    scanf("%1s", C);
    if(C[0] == '['){
        scanf("%d", &X);
        scanf("%1s", C);
        return var[X];
    }
    root = (Node*) calloc(1, sizeof(Node));
    root->op = C[0];
    root->left = parse();
    root->right = parse();
    root->left->parent = root;
    root->right->parent = root;
    return root;
}
void update(Node *root){
    if(root == NULL) return;
    if(root->op == '&') root->status = root->left->status && root->right->status;
    else if(root->op == '|') root->status = root->left->status || root->right->status;
    update(root->parent);
}
void freeTree(Node *root){
    if(root == NULL )return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main(){
    int T, N, M, X;
    Node *root;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++){
            var[i] = (Node*) calloc(1, sizeof(Node));
            var[i]->id = i;
        }
        root = parse();
        while(M--){
            scanf("%d", &X);
            var[X]->status = !(var[X]->status);
            update(var[X]->parent);
            printf("%d\n", root->status);
        }
        freeTree(root);
    }
}