// 12391.c
#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE {
	int num, id;
	struct _NODE *left, *right;
} Node;
Node *createNode(int num, int id){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->num = num;
    tmp->id = id;
    return tmp;
}
Node *build_tree(int *arr, int l, int r) {
	if(l>r) return NULL;
    int mid = (l+r)/2;
    Node *root = createNode(arr[mid], mid);
    root->left = build_tree(arr, l, mid-1);
    root->right = build_tree(arr, mid+1, r);
    return root;
}
int search(Node *now, int x) {
	while(now != NULL && now->num != x){
        if(now->num > x) now = now->left;
        else if(now->num < x) now = now->right;
    }
    if(now != NULL && now->num == x) return now->id;
    return 0;
}
void freeBST(Node *root){
    if(root == NULL) return;
	freeBST(root->left);
    freeBST(root->right);
    free(root);
}
int main(){
    for(int N, Q, A ;scanf("%d %d", &N, &Q) != EOF;){
        int *arr = (int*)calloc(N+1, sizeof(int)), idx;
        Node *root;
        for(int i = 1; i <= N; i++) scanf("%d", arr+i);
        root = build_tree(arr, 1, N);

        while(Q--){
            scanf("%d", &A);
            idx = search(root, A);
            if(idx == 0) puts("Break your bridge!");
            else printf("%d\n", idx);
        }

        freeBST(root);
        free(arr);
    }
}