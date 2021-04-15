// 12390.h
#include<stdio.h>
#include<stdlib.h>

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number

typedef struct _NODE
{
	int number;
	struct _NODE *ptr_to_right_node;
	struct _NODE *ptr_to_left_node;
} Node;

Node *createNode(int number){
	Node *tmp = (Node*)calloc(1, sizeof(Node));
	tmp->num = number;
	return tmp;
}

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
	Node *root;
	root = createNode(preorder[0]);
	int inorder_mid, left_cnt;
	for(int i = inorder_start; i <= inorder_end; i++){
		if(inorder[i] == preorder[0]){
			inorder_mid = i;
			break;
		}
	}
	left_cnt = inorder_mid - inorder_start;
	if(inorder_mid > inorder_start) root->left = buildTree(inorder, preorder+1, inorder_start, inorder_mid-1);
	if(inorder_mid < inorder_end) root->right = buildTree(inorder, preorder+left_cnt+1, inorder_mid+1, inorder_end);
	return root;
}

void showPostorder(Node* root){
	if(root->left != NULL) showPostorder(root->left);
	if(root->right != NULL) showPostorder(root->right);
	printf("%d ", root->num);
}

void freeTree(Node *root){
	if(root->left != NULL) freeTree(root->left);
	if(root->right != NULL) freeTree(root->right);
	free(root);
}

