// 12388.h
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
Node *removeNode(Node *root){
	Node *curr, *prev = NULL;
	if(root->left_child == NULL && root->right_child == NULL){
		free(root);
		return NULL;
	}
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
	else{
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

	free(root);
	return curr;
}

void build_tree(Node **now, int *arr, int l, int r){
	int mid = (l+r)/2;
	(*now) = createNode(arr[mid]);
	if(mid-1 >= l) build_tree(&(*now)->left_child, arr, l, mid-1);
	if(r >= mid+1) build_tree(&(*now)->right_child, arr, mid+1, r);
}
int query_heatstroke(Node *now, int x){
	while(now != NULL && now->level != x){
		if(now->level > x) now = now->left_child;
		else if(now->level < x) now = now->right_child;
	}
	if(now != NULL && now->level == x) return 1;
	return 0;
}
void eat_rat(Node **root, int x){
	Node *curr = (*root), *prev = NULL;
	while(curr->level != x){
		prev = curr;
		if(curr->level > x) curr = curr->left_child;
		else if(curr->level < x) curr = curr->right_child;
	}
	if(curr == (*root)) (*root) = removeNode((*root));
	else{
		if(prev->left_child == curr) prev->left_child = removeNode(curr);
		else if(prev->right_child == curr) prev->right_child = removeNode(curr);
	}
}
