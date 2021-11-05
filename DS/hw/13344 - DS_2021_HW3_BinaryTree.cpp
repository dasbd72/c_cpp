#include <cmath>
#include <iostream>
#include <string>
#include <utility>

#define PREORDER 1
#define INORDER 2
#define POSTORDER 3

typedef unsigned long long ULL;
typedef long long LL;

using namespace std;

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
        capacity = size;
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
        if (topidx == -1) throw "Stack is empty. No top.";
        return myArray[topidx];
    }
    void push(const T& item) {
        if (topidx == capacity - 1) this->extendCapacity();
        myArray[++topidx] = item;
        return;
    }
    void pop() {
        if (topidx == -1) throw "Stack is empty. Cannot pop.";
        topidx--;
    }
};

template <class T>
class Binary_Tree {
   private:
    T* myArray;
    int height;
    int capacity;

    int parent(int cur) const {
        if (cur == 0)
            return 0;
        else
            return ((cur - 1) / 2);
    }
    int lchild(int cur) const {
        return ((cur + 1) * 2 - 1);
    }
    int rchild(int cur) const {
        return ((cur + 1) * 2);
    }
    int calc_height(string exp) const {
        int cur_depth = 0, max_depth = 0;
        for (int i = 0; i < (int)exp.length(); i++) {
            if (exp[i] == '(')
                cur_depth++;
            else if (exp[i] == ')')
                cur_depth--;
            max_depth = (cur_depth > max_depth ? cur_depth : max_depth);
        }
        return max_depth - 1;
    }

   public:
    Binary_Tree() {
        myArray = nullptr;
    }
    ~Binary_Tree() {
        delete[] myArray;
    }
    void Construct(string exp) {
        int curnode = 0;
        myStack<int> st;  // 0 : go left, 1 : go right
        this->height = this->calc_height(exp);
        this->capacity = pow(2, this->height) - 1;
        this->myArray = new T[this->capacity];
        for (int i = 1, j; i < (int)exp.length() - 1; i++) {
            if (exp[i] == '(') {
                j = st.top();
                st.pop();
                if (j == 0) {
                    st.push(1);
                    curnode = this->lchild(curnode);
                } else if (j == 1) {
                    curnode = this->rchild(curnode);
                }
            } else if (exp[i] == ')') {
                curnode = this->parent(curnode);
            } else {
                j = i;
                while (isdigit(exp[j + 1])) j++;
                st.push(0);
                this->myArray[curnode] = (T)stoll(exp.substr(i, j + 1));
                i = j;
            }
        }
    }
    void Traverse(int order) const {
        int curnode = 0, way;
        myStack<int> st;  // < 0 : go left, 1 : go right, 2 : return >
        st.push(0);
        while (!st.empty()) {
            way = st.top();
            st.pop();
            if (way == 0) {
                if (order == PREORDER) cout << myArray[curnode] << ' ';
                st.push(1);
                if (lchild(curnode) < capacity) {
                    st.push(0);
                    curnode = lchild(curnode);
                }
            } else if (way == 1) {
                if (order == INORDER) cout << myArray[curnode] << ' ';
                st.push(2);
                if (rchild(curnode) < capacity) {
                    st.push(0);
                    curnode = rchild(curnode);
                }
            } else if (way == 2) {
                if (order == POSTORDER) cout << myArray[curnode] << ' ';
                curnode = parent(curnode);
            }
        }
        cout << '\n';
    }
    LL WeightSum() const {
    }
    LL MaximumPathSum() const {
    }
    LL BinaryTower() const {
    }
    bool Foldable() const {
    }
    void DeleteLeaf() {
    }
    void Invert() {
    }
    LL KingdonUnitePath() const {
    }
    void DEBUG() const {
        cout << "Capacity : " << this->capacity << '\n';
        for (int i = 0; i < this->capacity; i++) {
            cout << myArray[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    string exp, op;
    Binary_Tree<LL> bt;
    cin >> exp;
    bt.Construct(exp);
    // bt.DEBUG();
    while (cin >> op) {
        if (op == "End") break;

        if (op == "Traverse") {
            bt.Traverse(PREORDER);
            bt.Traverse(INORDER);
            bt.Traverse(POSTORDER);
        } else if (op == "WeightSum") {
            cout << bt.WeightSum() << '\n';
        } else if (op == "MaximumPathSum") {
            cout << bt.MaximumPathSum() << '\n';
        } else if (op == "BinaryTower") {
            cout << bt.BinaryTower() << '\n';
        } else if (op == "DeleteLeaf") {
            bt.DeleteLeaf();
        } else if (op == "Foldable") {
            cout << (bt.Foldable() ? "Yes" : "No") << '\n';
        } else if (op == "Invert") {
            bt.Invert();
        } else if (op == "KingdomUnitedPath") {
            cout << bt.KingdonUnitePath() << '\n';
        }
    }
    return 0;
}