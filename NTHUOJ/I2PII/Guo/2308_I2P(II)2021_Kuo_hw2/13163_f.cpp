#include <iostream>
#include "13163.h"
using namespace std;
int ftag = 0;
KuoYangPresent::KuoYangPresent(int k){
	sz = 0;
	KuoYangPresent::k = k;
	head = NULL;
	mid = NULL;
	tail = NULL;
}
void KuoYangPresent::Push(int x){
	Node *tmp = new Node;
	tmp->next = tmp->prev = NULL;
	tmp->val = x;
	tmp->tag = ftag;

	if(!tail) head = tail = mid = tmp;
	else{
		tmp->prev = tail;
		tail = tail->next = tmp;
		if(sz % 2 == 0 && mid->next) mid = mid->next; 
	}
	sz++;
}
void KuoYangPresent::Pop(){
	if(sz == 0) return;
	Node *tofree = mid;
	
	if(sz == 1) head = tail = mid = NULL;
	else if(sz == 2) head = mid = mid->next, head->prev = NULL;
	else{
		mid->next->prev = mid->prev;
		mid->prev->next = mid->next;
		if(sz % 2) mid = mid->prev;
		else mid = mid->next;
	}
	delete(tofree);
	sz--;
}
void KuoYangPresent::ProgrammingTanoshi(){
	ftag++;
}
void KuoYangPresent::KuoYangTeTe(){
	Node *curr = head;
	while(curr){
		if(curr->tag < ftag) curr->val %= k;
		curr = curr->next;
	}
}
void KuoYangPresent::PrintList(){
	Node *curr = head;
	while(curr){
		cout << curr->val << ' ';
		curr = curr->next;
	}
	cout << endl;
}
