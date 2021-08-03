#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    Node *lchild, *rchild;
    Node(int key = 0) : key(key) {
        lchild = rchild = nullptr;
    }
};
class BST {
   private:
    Node *root;

   public:
    BST() {
        root = nullptr;
    }
    Node *search(int key) {
        Node *curr = root;
        while (curr && curr->key != key) {
            if (key < curr->key)
                curr = curr->lchild;
            else if (key > curr->key)
                curr = curr->rchild;
        }
        return curr;
    }
    bool insert(int key) {
        return insert(root, key);
    }
    bool insert(Node *&node, int key) {
        if (!node) {
            node = new Node(key);
        } else if (key <= node->key) {
            insert(node->lchild, key);
        } else {
            insert(node->rchild, key);
        }
        return true;
    }
    bool remove(int key) {
        return this->remove(root, key);
    }
    bool remove(Node *&node, int key) {
        if (!node)
            return false;
        else {
            if (key == node->key)
                return remove(node);
            else if (key < node->key)
                return remove(node->lchild, key);
            else
                return remove(node->rchild, key);
        }
    }
    bool remove(Node *&node) {
        Node *todelete, *curr, *prev;
        if (!node->lchild && !node->rchild) {
            delete node;
            node = nullptr;
        } else if (!node->lchild) {
            todelete = node;
            node = node->rchild;
            delete todelete;
        } else if (!node->rchild) {
            todelete = node;
            node = node->lchild;
            delete todelete;
        } else {
            todelete = prev = node;
            curr = node->lchild;
            while (curr->rchild) {  // get largest less than node
                prev = curr;
                curr = curr->rchild;
            }
            if (prev != node)
                prev->rchild = curr->lchild;
            else
                prev->lchild = curr->lchild;
            curr->lchild = node->lchild;
            curr->rchild = node->rchild;
            node = curr;
            delete todelete;
        }
        return true;
    }
    void print() {
        print(root);
        cout << "\n";
    }
    void print(Node *node) {
        if (!node) return;
        print(node->lchild);
        cout << node->key << " ";
        print(node->rchild);
    }
};
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    BST bst;
    string op;
    int x;
    while (cin >> op >> x) {
        if (op[0] == 'i') {
            bst.insert(x);
        } else if (op[0] == 'd') {
            bst.remove(x);
        }
        bst.print();
    }

    return 0;
}