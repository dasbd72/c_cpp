#include <cstddef>

class _node{
    public:
        int data;
        _node* next,*prev;
        _node(int d=0){data = d; next=prev=NULL;}

};
class _dequeue{
    protected:
        _node* Begin,*End;

    public:
        _dequeue(){
            Begin = new _node(0);
            End = new _node(0);
            Begin->next=End;
            End->prev=Begin;
        }
        bool Empty(){
            if(Begin==NULL || Begin->next==End) return true;
            return false;
        }
        virtual void push(const _node) = 0;
        virtual void pop() = 0;
        virtual _node* get_data() = 0;
};

class _stack : public _dequeue{
    public:
        _stack():_dequeue(){}
        void push(const _node N);
        void pop();
        _node* get_data();

};
class _queue : public _dequeue{
    public:
        _queue():_dequeue(){}
        void push(const _node N);
        void pop();
        _node* get_data();

};

void _stack::push(const _node N){
    _node *newNode = new _node(N.data);
    newNode->next = Begin->next;
    newNode->prev = Begin;
    Begin->next->prev = newNode;
    Begin->next = newNode;
}
void _stack::pop(){
    _node *tofree;
    if(Empty()) return;
    else {
        tofree = Begin->next;
        Begin->next = tofree->next;
        tofree->next->prev = Begin;
        delete tofree;
    }
}
_node* _stack::get_data(){
    if(Empty()) return NULL;
    return Begin->next;
}

void _queue::push(const _node N){
    _node *newNode = new _node(N.data);
    newNode->next = End;
    newNode->prev = End->prev;
    End->prev->next = newNode;
    End->prev = newNode;
}
void _queue::pop(){
    _node *tofree;
    if(Empty()) return;
    else {
        tofree = Begin->next;
        Begin->next = tofree->next;
        tofree->next->prev = Begin;
        delete tofree;
    }
}
_node* _queue::get_data(){
    if(Empty()) return NULL;
    return Begin->next;
}