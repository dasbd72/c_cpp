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
        if (search(key))
            return false;
        else
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
    void query(int key) {
        Node *r, *l, *curr = root;
        r = l = nullptr;
        while (curr && key != curr->key) {
            if (key < curr->key) {
                r = curr;
                curr = curr->lchild;
            } else if (key > curr->key) {
                l = curr;
                curr = curr->rchild;
            }
        }

        if (curr && key == curr->key) {
            cout << key << "\n";
        } else {
            int ldist = 0x7fffffff, rdist = 0x7fffffff;
            if (l) ldist = abs(l->key - key);
            if (r) rdist = abs(r->key - key);
            if (ldist == rdist)
                cout << l->key << " " << r->key << "\n";
            else if (ldist < rdist)
                cout << l->key << "\n";
            else if (ldist > rdist)
                cout << r->key << "\n";
        }
    }
};

int main() {
    int N, x;
    string op;
    BST bst;

    cin >> N;
    while (N--) {
        cin >> op >> x;
        if (op == "insert") {
            bst.insert(x);
        } else if (op == "delete") {
            bst.remove(x);
        } else if (op == "query") {
            bst.query(x);
        }
    }
    return 0;
}