#ifndef FUNCTION_H
#define FUNCTION_H

/* an abstract class for the container used in this problem */
class ContainerBase {
	public:
		/* for the first-type operation */
		virtual int print() = 0;
		/* for the second-type operation */
		virtual void move(int) = 0;
		/* for the third-type operation */
		virtual void remove() = 0;
		/* for the fourth-type operation */
		virtual void reverse() = 0;
		int getSize() { return size; }

		virtual ~ContainerBase() {}
	protected:
		int size;	// the number of elements(people) in the container
		bool rev;	// record whether the row need to be reversed or not
};

/* array class deriving from ContainerBase */
class Array final : public ContainerBase {
	public:
		Array() {}
		Array(int n, int *arr) {
			size = n;
			
			mem = new int[size + 1];
			for(int i=1;i<=size;i++)	mem[i] = arr[i];
			cur = 1;
			
			rev = false;
		}
		
		virtual int print() override { return mem[cur]; }
		/* TODO */
		virtual void move(int) override;
		/* TODO */
		virtual void remove() override;
		/* TODO */
		virtual void reverse() override;
		
		~Array() { delete[] mem; }
	private:
		int *mem;	// array for maintaining all the elements(the happy value of all the people)
		int cur;	// record who is carrying the ball
};

/* doubly linked list class deriving from ContainerBase */
class List final : public ContainerBase {
	public:
		List() {}
		List(int n, int *arr) {
			size = n;
			
			cur = new Node(arr[1]);
			Node *back = cur;
			for(int i=2;i<=n;i++) {
				Node *newNode = new Node(arr[i]);
				back->insertBack(newNode);
				back = newNode;
			}

			rev = false;
		}
		
		virtual int print() override { return cur->val; }
		/* TODO */
		virtual void move(int) override;
		/* TODO */
		virtual void remove() override;
		/* TODO */
		virtual void reverse() override;
		
		~List() { for(int i=1;i<=size;i++)	cur = cur->remove(); }
	private:
		/* nested class for the node in linked list */
		class Node {
			public:
				Node *pre, *nxt;
				int val;
				
				Node() {}
				Node(int newVal) : pre(nullptr), nxt(nullptr), val(newVal) {}
				/* insert a new node after the current node */
				void insertBack(Node *newNode) {
					nxt = newNode;
					newNode->pre = this;
				}
				/* remove the current node and return the next node(or the previous node if the next node doesn't exist) */
				Node* remove(bool preFirst=false) {
					Node *ret = (nxt == nullptr ? pre : nxt);
					if(preFirst && pre != nullptr)	ret = pre;
					if(pre != nullptr)	pre->nxt = nxt;
					if(nxt != nullptr)	nxt->pre = pre;
					delete this;
					return ret;
				}
		} *cur;	// record who is carrying the ball
};

/* a class for operation */
class Operation {
	public:
		int type,d;
};

/* TODO: create array/linked list based on the number of the second-type and the third-type operations. then return it */
ContainerBase* create(int, int*, int, int);

#endif

// #include "function.h"
#include <iostream>
using namespace std;

void Array::move(int d) {
	if(!rev) cur += d;
	else cur -= d;
	if(cur > size) cur = size;
	else if(cur < 1) cur = 1;
}

void Array::remove() {
	if(size == 0) return;

	for(int i = cur; i < size; i++) {
		mem[i] = mem[i+1];
	}
	if(rev) cur--;
	size--;
	if(cur > size) cur = size;
	else if(cur < 1) cur = 1;
}

void Array::reverse() {
	rev = !rev;
}

void List::move(int d) {
	if(size == 0) return;
	d *= (!rev)?1:-1;
	if(d > 0) while(cur->nxt && d--) cur = cur->nxt;
	else while(cur->pre && d++) cur = cur->pre;
}

void List::remove() {
	if(size == 0) return;
	cur = cur->remove(rev);
	size--;
}

void List::reverse() {
	rev = !rev;
}

ContainerBase* create(int n, int *arr, int op2Cnt, int op3Cnt) {
	if(op3Cnt >= op2Cnt)
		return new List(n, arr);
	else 
		return new Array(n, arr);
}
/*
1
5
1 2 3 4 5
12
1
2 6
3
1
3
1
3
1
3
1
3
1

*/
