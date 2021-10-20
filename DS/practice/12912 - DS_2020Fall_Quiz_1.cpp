#include <iostream>
#include <string>
using namespace std;

class LinkedList;

class ListNode {
   public:
    ListNode() : data(' '), next(0), pre(0){};
    ListNode(char c) : data(c), next(0), pre(0){};

    friend class LinkedList;

   private:
    char data;
    ListNode *next;
    ListNode *pre;
};

class LinkedList {
   public:
    LinkedList() {
        head = new ListNode('\0');
        cursor = new ListNode('|');
        head->next = cursor;
        cursor->pre = head;
        cursor->next = new ListNode('\0');
        cursor->next->pre = cursor;
    };
    void add_node(char c);
    void move_right(int p);
    void move_left(int p);
    void backspace();
    void print();

   private:
    ListNode *head;
    ListNode *cursor;

    ListNode *rm(ListNode *node);
};

void LinkedList::backspace() {
    // your implement
    if (cursor->pre == head) return;
    delete this->rm(cursor->pre);
    return;
}

void LinkedList::print() {
    // your implement
    ListNode *tmp = head->next;
    while (tmp->data != '\0') {
        if (tmp->data != '|')
            cout << tmp->data;
        tmp = tmp->next;
    }
    cout << "\n";
    return;
}

void LinkedList::add_node(char c) {
    // your implement
    ListNode *tmp = new ListNode(c);
    tmp->pre = cursor->pre;
    tmp->next = cursor;
    tmp->pre->next = tmp;
    cursor->pre = tmp;
    return;
}

void LinkedList::move_right(int p) {
    ListNode *tmp = cursor;
    // Stop when reached tail or reached target
    while (tmp->next->data != '\0' && p--) {
        tmp = tmp->next;
    }
    // Don't do any thing if didn't move
    if (cursor == tmp) return;
    // Remove cursor from the original position
    this->rm(cursor);
    // Insert it next to tmp
    cursor->next = tmp->next;
    cursor->pre = tmp;
    tmp->next = cursor;
    cursor->next->pre = cursor;
}
void LinkedList::move_left(int p) {
    ListNode *tmp = cursor;
    // Stop when reached head or reached target
    while (tmp->pre->data != '\0' && p--) {
        tmp = tmp->pre;
    }
    // Don't do any thing if didn't move
    if (cursor == tmp) return;
    // Remove cursor from the original position
    this->rm(cursor);
    // Insert it pre to tmp
    cursor->pre = tmp->pre;
    cursor->next = tmp;
    tmp->pre = cursor;
    cursor->pre->next = cursor;
}

ListNode *LinkedList::rm(ListNode *node) {
    ListNode *preNode = node->pre, *nxtNode = node->next;
    node->pre = node->next = nullptr;
    preNode->next = nxtNode;
    nxtNode->pre = preNode;
    return node;
}

int main() {
    LinkedList list;
    string command;
    string input;
    int p;
    while (cin >> command) {
        if (command == "Type") {
            cin >> input;
            if (input.empty()) {
                continue;
            } else {
                for (int i = 0; i < input.length(); i++) {
                    list.add_node(input[i]);
                }
            }
        } else if (command == "Move") {
            cin >> p;
            if (p > 0) {
                list.move_right(p);
            } else if (p < 0) {
                list.move_left(-p);
            } else {
                continue;
            }
        } else if (command == "Backspace") {
            list.backspace();
        } else if (command == "Print") {
            list.print();
        } else {
            continue;
        }
    }
    return 0;
}
