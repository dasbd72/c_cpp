#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE {
	int level;
	struct _NODE *left_child, *right_child;
} Node;

Node *createNode(int level){
	Node *tmp = (Node*)calloc(1, sizeof(Node));
	tmp->level = level;
	return tmp;
}
Node *deleteNode(Node *root){
	Node *curr, *prev = NULL;
	if(root->left_child){
		curr = root->left_child;
		while(curr->right_child){
			prev = curr;
			curr = curr->right_child;
		}
		if(prev){
			prev->right_child = curr->left_child;
			curr->left_child = root->left_child;
		}
		curr->right_child = root->right_child;

	}
	else if(root->right_child){
		curr = root->right_child;
		while(curr->left_child){
			prev = curr;
			curr = curr->left_child;
		}
		if(prev){
			prev->left_child = curr->right_child;
			curr->right_child = root->right_child;
		}
		curr->left_child = root->left_child;
	}
	else curr = NULL;
	free(root);
	return curr;
}
void build_tree(Node **now, int *arr, int l, int r){
	int mid = (l+r)/2;
	*now = createNode(arr[mid]);
	if(mid-1 >= l) build_tree(&(*now)->left_child, arr, l, mid-1);
	if(r >= mid+1) build_tree(&(*now)->right_child, arr, mid+1, r);
	return;
}
int query_heatstroke(Node *now, int x){
	while(now != NULL && now->level != x){
		if(now->level > x) now = now->left_child;
		else if(now->level < x) now = now->right_child;
	}
	if(now->level == x) return 1;
	return 0;
}
void eat_rat(Node **root, int x){
	Node *now = *root, *prev = NULL;
	while(now != NULL && now->level != x){
		prev = now;
		if(now->level > x) now = now->left_child;
		else if(now->level < x) now = now->right_child;
	}
	if(now == *root) *root = deleteNode(now);
	else{
		if(prev->left_child == now) prev->left_child = deleteNode(now);
		else if(prev->right_child == now) prev->right_child = deleteNode(now);
	}
}
void buy_rat(Node **root, int x){
	Node *now = *root, *prev = NULL;
	while(now != NULL && now->level != x){
		prev = now;
		if(now->level > x) now = now->left_child;
		else if(now->level < x) now = now->right_child;
	}
	
}
