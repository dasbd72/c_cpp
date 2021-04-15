// AC
#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 35
typedef struct Node{
    char key;
    struct Node *left, *right;
} Node;
char expr[MAXLEN];
int parsePos;

int keyIsOp(char key){
    if(key == '|' || key == '&') return 1;
    return 0;
}
Node *createNode(char key){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->key = key;
    return tmp;
}
Node *buildTree(){
    Node *root = createNode(expr[parsePos]);
    if(expr[parsePos] == 0 || !keyIsOp(root->key)) return root;
    parsePos++;
    root->left = buildTree();
    parsePos++;
    root->right = buildTree();
    return root;
}
int solve(Node *root, int bit){
    switch (root->key){
        case 'A':
            return bit&(1<<3);
        case 'B':
            return bit&(1<<2);
        case 'C':
            return bit&(1<<1);
        case 'D':
            return bit&(1<<0);
        case '|':
            return solve(root->left, bit) || solve(root->right, bit);
        case '&':
            return solve(root->left, bit) && solve(root->right, bit);
        default:
            break;
    }
    return 0;
}
int main(){
    scanf("%s", expr);
    parsePos = 0;
    Node *root = buildTree();
    for(int bit = 0; bit < 16; bit++){
        for(int i = 3; i >= 0; i--) printf("%d ", (bit & (1 << i)) ? 1 : 0);
        printf("%d\n", solve(root, bit));
    }
}