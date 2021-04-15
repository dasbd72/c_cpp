#ifndef NODE
#define NODE
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

Node *makeNode(unsigned short val){
	Node *tmp = (Node*)calloc(1, sizeof(Node));
	tmp->val = val;
	return tmp;
}
void do_I(Node **head,size_t pos,unsigned short val){
	Node *tmp = makeNode(val), *curr = *head;
	if(*head == NULL || pos == 0){
		if(*head) (*head)->prev = tmp;
		tmp->next = *head;
		*head = tmp;
		return;
	}
	for(size_t i = 1; i < pos; i++){
		if(curr->next == NULL) break;
		curr = curr->next;
	}
	tmp->prev = curr;
	tmp->next = curr->next;
	if(curr->next) curr->next->prev = tmp;
	curr->next = tmp;
	return;
}
void do_E(Node **head,size_t begin_pos,size_t end_pos){
	Node *curr=*head, *lnode = NULL, *rnode = NULL, *tofree;
	if(*head == NULL || begin_pos >= end_pos) return;
	for(size_t i = 0; curr != NULL; i++){
		if(i == begin_pos) lnode = curr;
		if(i + 1 == end_pos || curr->next == NULL){
			if(lnode == NULL) return;
			else rnode = curr;
			break;
		}
		curr = curr->next;
	}
	if(*head == lnode) *head = rnode->next;
	else{
		lnode->prev->next = rnode->next;
		if(rnode->next != NULL) rnode->next->prev = lnode->prev;
	}
	rnode->next = NULL;
	while(lnode != NULL){
		tofree = lnode;
		lnode = lnode->next;
		free(tofree);
	}
}
void do_P(Node  *head,size_t pos){
	if(head == NULL) return;
	for(size_t i = 0; i < pos; i++){
		if(head->next == NULL) break;
		head = head->next;
	}
	printf("%d ", head->val);
}
void do_R(Node **head,unsigned short val){
	Node *curr = *head, *tofree;
	while(curr != NULL){
		if(curr->val == val){
			tofree = curr;
			if(curr == *head){
				*head = curr = curr->next;
				if(curr != NULL) curr->prev = NULL;
			}
			else{
				curr->prev->next = curr->next;
				if(curr->next) curr->next->prev = curr->prev;
				curr = curr->next;
			}
			free(tofree);
		}
		else curr = curr->next;
	}
}
void do_S(Node  *head){
	while(head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
}

#endif