// AC
#ifndef NODE
#define NODE
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
int hasprinted;
typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

Node *createNode(unsigned short val){
	Node *tmp = (Node*)calloc(1, sizeof(Node));
	tmp->val = val;
	return tmp;
}
void do_I(Node **head,size_t pos,unsigned short val){
	Node *tmp = createNode(val), *curr = *head;
	if(*head == NULL || pos == 0){
		if(*head != NULL) tmp->next = *head, (*head)->prev = tmp;
		*head = tmp;
	}
	else{
		for(size_t i = 1; i < pos; i++){
			if(curr->next == NULL) break;
			else curr = curr->next;
		}
		tmp->next = curr->next;
		curr->next = tmp;
		tmp->prev = curr;
		if(tmp->next != NULL) tmp->next->prev = tmp;
	}
}
void do_E(Node **head,size_t begin_pos,size_t end_pos){
	if(*head == NULL )return;
	Node *curr = *head, *left = NULL, *tmp;
	if(begin_pos == end_pos) end_pos++;
	for(size_t i = 0; i < end_pos; i++){
		if(i == begin_pos) left = curr;
		if(curr->next == NULL){
			if(left == NULL) return;
			else break;
		}
		if(i+1 < end_pos)curr = curr->next;
	}
	if(*head == left){
		*head = curr->next;
		if(*head != NULL) (*head)->prev = NULL;
	}
	else{
		left->prev->next = curr->next;
		if(curr->next != NULL) curr->next->prev = left->prev;
	}
	curr->next = NULL;
	while(left != NULL){
		tmp = left;
		left = left->next;
		free(tmp);
	}
}
void do_P(Node  *head,size_t pos){
	if(head == NULL ) return;
	for(size_t i = 0; i < pos; i++){
		if(head->next == NULL) break;
		head = head->next;
	}
	printf("%d ", head->val);
}
void do_R(Node **head,unsigned short val){
	Node *curr = (*head), *tmp;
	while(curr != NULL){
		if(curr->val == val){
			if(curr == (*head)){
				*head = curr->next;
				if(*head != NULL)(*head)->prev = NULL;
			}
			else{
				curr->prev->next = curr->next;
				if(curr->next != NULL) curr->next->prev = curr->prev;
			}
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}
		else curr = curr->next;
	}
}
void do_S(Node  *head){
	while(head != NULL){
		printf("%d ", head->val);
		head = head->next;
	}
}

#endif

/*
13
I 1 0
S
I 3 1
S
P 2
S
I 0 1
S
R 1
S
*/