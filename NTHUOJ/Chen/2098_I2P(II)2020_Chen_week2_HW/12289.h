// passed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NODE
{
	char color[10];
	struct _NODE *next;
} Node;

static Node* new_node(char* color){
	Node* tmp = (Node*)malloc(sizeof(Node));
	strcpy(tmp->color, color);
	tmp->next = NULL;
	return tmp;
}

void insert(Node** head, char* color, int dest){
	Node* curr = *head, *tmp = new_node(color);
	while(curr->next && dest--) curr = curr->next;
	tmp->next = curr->next;
	curr->next = tmp;
}

void erase1(Node** head, int dest){
	Node *curr = *head, *tofree;
	while(curr->next && --dest) curr = curr->next;
	if(curr->next){
		tofree = curr->next;
		curr->next = curr->next->next;
		free(tofree);
	}
}

void erase2(Node** head, char* color){
	Node *curr = *head;
	while(curr->next){
		if(strcmp(curr->next->color, color) == 0) erase1(&curr, 1);
		else curr = curr->next;
	}
}

void reverse(Node** head, int l, int r){
	Node *lpre = *head, *rnex, *curr, *prev, *tmp;
	int i = 0;
	while(lpre->next && i < l-1) lpre = lpre->next, i++;
	rnex = lpre;
	curr = lpre->next;
	while(rnex && i < r+1) rnex = rnex->next, i++;
	prev = rnex;
	while(curr != rnex){
		tmp = curr;
		curr = curr->next;
		tmp->next = prev;
		prev = tmp;
	}
	lpre->next = prev;
}

void show(Node **);