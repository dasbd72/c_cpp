// pass
#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character
#define _curr (*curr)

typedef struct _NODE
{
	char character;
	struct _NODE *ptr_to_next_node;
	struct _NODE *ptr_to_prev_node;
} Node;

Node *head, *tail;

Node *createNode(char ch){
	Node *tmp = (Node*)calloc(1, sizeof(Node));
	tmp->character = ch;
	return tmp;
}

int countNode(){
	Node *tmp = head;
	int cnt = 1;
	while(tmp != tail){
		tmp = tmp->next;
		cnt++;
	}
	return cnt;
}

void insert(Node** curr, char ch){
	Node *tmp = createNode(ch);
	if(_curr == tail) tail = tmp;
	tmp->next = _curr->next;
	tmp->prev = _curr;
	_curr->next->prev = tmp;
	_curr->next = tmp;
}

void deletion(Node** curr){
	if(_curr == tail) return;
	Node *tofree = _curr->next, *tmp = _curr->next->next;
	if(tofree == tail) tail = _curr;
	_curr->next = tmp;
	tmp->prev = _curr;
	free(tofree);
}

void backspace(Node** curr){
	if(_curr == head) return;
	Node *tofree = _curr, *tmp = _curr->next;
	_curr = _curr->prev;
	if(tofree == tail) tail = _curr;
	_curr->next = tmp;
	tmp->prev = _curr;
	free(tofree);
}

void go_left(Node** curr, int step){
	int sz = countNode();
	step %= sz;
	while(step--) _curr = _curr->prev;
}

void go_right(Node** curr, int step){
	int sz = countNode();
	step %= sz;
	while(step--) _curr = _curr->next;
}

void go_home(Node** curr){
	_curr = head;
}

void go_end(Node** curr){
	_curr = tail;
}

void show();
