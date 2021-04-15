#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
typedef struct Node{
    int num;
    struct Node *left, *right;
} Node;
Node *makeNode(int num){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->num = num;
    return tmp;
}
bool searchNode(Node *root, int num){
    while(root != NULL){
        if(num == root->num) return true;
        else if(num > root->num) root = root->right;
        else if(num < root->num) root = root->left;
    }
    return false;
}
void pushNode(Node **root, int num){
    Node *tmp = makeNode(num), *curr = *root;
    if(curr == NULL) *root = tmp;
    else while(1){
        if(num > curr->num){
            if(curr->right == NULL) {
                curr->right = tmp;
                break;
            }
            curr = curr->right;
        }
        else if(num < curr->num){
            if(curr->left == NULL){
                curr->left = tmp;
                break;
            }
            curr = curr->left;
        }
    }
}
void printInorder(Node *root){
    if(root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->num);
    printInorder(root->right);
}
int getMaxHeight(Node *root){
    if(root == NULL) return 0;
    return(1 + fmax(getMaxHeight(root->left), getMaxHeight(root->right)));
}
int getSumLevel(Node *root, int level){
    if(root == NULL) return 0;
    if(level == 1) return root->num;
    return getSumLevel(root->left, level-1) + getSumLevel(root->right, level-1);
}
int getCntLevel(Node *root, int level){
    if(root == NULL) return 0;
    if(level == 1) return 1;
    return getCntLevel(root->left, level-1) + getCntLevel(root->right, level-1);
}
int main(){
    Node *root=NULL;
    int N, X, M, maxHeight;
    char cmd[10];
    scanf("%d", &N);
    while(N--){
        scanf("%d", &X);
        if(searchNode(root, X)) continue;
        pushNode(&root, X);
    }
    maxHeight = getMaxHeight(root);
    scanf("%d", &M);
    while(M--){
        bool skipped = false;
        scanf("%s", cmd);
        if(strcmp(cmd, "P") == 0){
            static bool done = 0;
            if(done){
                skipped = true;
                continue;
            }
            done = 1;
            if(root == NULL) printf("NULL");
            else printInorder(root);
            puts("");
        }
        else if(strcmp(cmd, "GetMax") == 0){
            static bool done = 0;
            if(done){
                skipped = true;
                continue;
            }
            done = 1;
            printf("%d\n", maxHeight);
        }
        else if(strcmp(cmd, "SumLevel") == 0){
            scanf("%d", &X);
            static Node *que=NULL;
            if(searchNode(que, X)){
                skipped = true;
                continue;
            }
            pushNode(&que, X);
            printf("%d\n", getSumLevel(root, X));
        }
        else if(strcmp(cmd, "AverLevel") == 0){
            scanf("%d", &X);
            static Node *que=NULL;
            if(searchNode(que, X)){
                skipped = true;
                continue;
            }
            pushNode(&que, X);
            if(X > maxHeight || X == 0) printf("0\n");
            else printf("%.3f\n", (float)getSumLevel(root, X) / (float)getCntLevel(root, X));
        }
        if(skipped && M == 0) puts("");
    }
}