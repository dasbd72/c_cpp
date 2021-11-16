#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

#define PREORDER 1
#define INORDER 2
#define POSTORDER 3

typedef long long LL;

using namespace std;

template <class T>
class myQueue {
   private:
    /* data */
    T* myArray;
    int rearidx, frontidx;
    int capacity;

    void extendCapacity() {
        int oldcapacity = capacity;
        capacity *= 2;
        T* anotherArray = myArray;
        myArray = new T[capacity];
        for (int i = 0, j = frontidx; j != rearidx; i++, j = (j + 1) % oldcapacity)
            myArray[i] = anotherArray[j];
        frontidx = 0;
        rearidx = oldcapacity - 1;
        delete[] anotherArray;
        return;
    }

   public:
    myQueue(int size = 1) {
        capacity = ((size + 1) / 2) * 2;
        myArray = new T[capacity];
        rearidx = frontidx = 0;
    }
    ~myQueue() {
        delete[] myArray;
    }
    bool empty() const {
        return rearidx == frontidx;
    }
    T& front() const {
        if (this->empty())
            throw "Queue is empty. No front.";
        return myArray[frontidx];
    }
    void push(const T& item) {
        if ((rearidx + 1) % capacity == frontidx)
            this->extendCapacity();
        myArray[rearidx] = item;
        rearidx = (rearidx + 1) % capacity;
        return;
    }
    void pop() {
        if (this->empty())
            throw "Queue is empty. Cannot pop.";
        frontidx = (frontidx + 1) % capacity;
    }
};

template <class T>
class myStack {
   private:
    /* data */
    T* myArray;
    int topidx;
    int capacity;

    void extendCapacity() {
        capacity *= 2;
        T* anotherArray = myArray;
        myArray = new T[capacity];
        for (int i = 0; i <= topidx; i++)
            myArray[i] = anotherArray[i];
        delete[] anotherArray;
        return;
    }

   public:
    myStack(int size = 1) {
        capacity = ((size + 1) / 2) * 2;
        myArray = new T[capacity];
        topidx = -1;
    }
    ~myStack() {
        delete[] myArray;
    }
    bool empty() const {
        return topidx == -1;
    }
    T& top() const {
        if (topidx == -1)
            throw "Stack is empty. No top.";
        return myArray[topidx];
    }
    void push(const T& item) {
        if (topidx == capacity - 1)
            this->extendCapacity();
        myArray[++topidx] = item;
        return;
    }
    void pop() {
        if (topidx == -1)
            throw "Stack is empty. Cannot pop.";
        topidx--;
    }
};

class Node {
   public:
    LL data;
    Node* left;
    Node* right;
    Node(LL data = 0) : data(data) {
        left = right = nullptr;
    }
    bool isleaf() const {
        return (left == nullptr && right == nullptr);
    }
};
class Binary_Tree {
   private:
    Node* root;

    void deltree(Node* node) const {
        if (!node)
            return;
        deltree(node->left);
        deltree(node->right);
        delete node;
    }

   public:
    Binary_Tree() {
        root = nullptr;
    }
    ~Binary_Tree() {
        deltree(root);
    }
    void Construct(string exp) {
        myStack<tuple<int, Node*, int>> expSt;  // start, parent, direction
        myStack<int> parSt;                     // position
        int* pos = new int[exp.length()];       // next position
        int numl, numr;
        int start, direction;
        Node *parent, *newnode;

        for (int i = exp.length() - 1; i >= 0; i--) {  // Locate parenthesis pair
            pos[i] = 0;
            if (exp[i] == '(') {
                pos[i] = parSt.top();
                parSt.pop();
            } else if (exp[i] == ')')
                parSt.push(i);
        }
        expSt.push(make_tuple(0, nullptr, 0));
        while (!expSt.empty()) {
            start = get<0>(expSt.top());
            parent = get<1>(expSt.top());
            direction = get<2>(expSt.top());
            expSt.pop();
            if (pos[start] == start + 1)
                continue;

            numl = numr = start + 1;
            while (isdigit(exp[numr]) || exp[numr] == '-') numr++;
            newnode = new Node(stoll(exp.substr(numl, numr - numl)));

            if (parent == nullptr)
                root = parent = newnode;
            else if (direction == 0)
                parent = parent->left = newnode;
            else if (direction == 1)
                parent = parent->right = newnode;

            expSt.push(make_tuple(numr, parent, 0));           // left subtree
            expSt.push(make_tuple(pos[numr] + 1, parent, 1));  // right subtree
        }
        delete[] pos;
    }
    void Traverse(int order) const {
        bool output;
        Node* curnode;
        myStack<tuple<bool, Node*>> st;  // operation, node
        st.push(make_tuple(false, root));
        while (!st.empty()) {
            output = get<0>(st.top());
            curnode = get<1>(st.top());
            st.pop();
            if (curnode == nullptr)
                continue;
            if (output)
                cout << curnode->data << " ";
            else {
                if (order == PREORDER) {
                    st.push(make_tuple(false, curnode->right));
                    st.push(make_tuple(false, curnode->left));
                    st.push(make_tuple(true, curnode));
                } else if (order == INORDER) {
                    st.push(make_tuple(false, curnode->right));
                    st.push(make_tuple(true, curnode));
                    st.push(make_tuple(false, curnode->left));
                } else if (order == POSTORDER) {
                    st.push(make_tuple(true, curnode));
                    st.push(make_tuple(false, curnode->right));
                    st.push(make_tuple(false, curnode->left));
                }
            }
        }
        cout << '\n';
    }
    LL MagicJump() {
        myQueue<tuple<int, int, Node*>> que;  // Rank, idx(in rank), node
        int rank, idx;
        Node* node;
        int minidx = 1, maxidx = 1, currank = 0;
        int maximum = 0;
        bool flag = false;

        que.push(make_tuple(1, 1, root));
        while (!que.empty()) {
            rank = get<0>(que.front());
            idx = get<1>(que.front());
            node = get<2>(que.front());
            que.pop();
            if (rank != currank) {
                // cout << rank << " " << (node ? node->data : -1) << " " << minidx << " " << maxidx << "\n";  //DEBUG
                maximum = max((maxidx - minidx == 0 ? 0 : maxidx - minidx + 1), maximum);
                currank = rank;
                flag = false;
            }
            if (!node)
                continue;
            // cout << rank << " " << node->data << "\n";  //DEBUG
            if (!flag) {
                minidx = idx;
                flag = true;
            }
            maxidx = idx;
            que.push(make_tuple(rank + 1, idx * 2 - 1, node->left));
            que.push(make_tuple(rank + 1, idx * 2, node->right));
        }
        return maximum;
    }
};

int main() {
    string exp;
    while (cin >> exp) {
        Binary_Tree bt;
        bt.Construct(exp);
        // bt.Traverse(INORDER);  //DEBUG
        cout << bt.MagicJump() << "\n";
    }
    return 0;
}
/* 
(1(2(4()())(5()()))(3(6()())(7()())))
(1(2()(5()()))(3(6()())()))
 */