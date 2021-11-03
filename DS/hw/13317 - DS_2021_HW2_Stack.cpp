#include <iostream>
using namespace std;

template <class T1, class T2>
class myPair {
   public:
    T1 first;
    T2 second;
    myPair() : first(0), second(0) {}
    myPair(T1 first, T2 second) : first(first), second(second) {}
    ~myPair() {}
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
        T* anotherArray = new T[capacity];
        for (int i = 0; i <= topidx; i++) {
            anotherArray[i] = myArray[i];
        }
        swap(anotherArray, myArray);
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
    // For testing
    void print() {
        for (int i = 0; i <= topidx; i++) {
            cout << myArray[i] << (i == topidx ? "" : " ");
        }
        cout << "\n";
    }
};

int main() {
    int N, H;
    myStack<myPair<int, int>> height_position_stack;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H;
        while (!height_position_stack.empty() && height_position_stack.top().first >= H) {
            height_position_stack.pop();
        }
        if (!height_position_stack.empty())
            cout << height_position_stack.top().second << " ";
        else
            cout << "0 ";
        height_position_stack.push(myPair<int, int>(H, i));
    }
    cout << "\n";
}

void myPair_test_function() {
    myPair<int, int> mp(100, 200);
    cout << mp.first << " " << mp.second << "\n";
}

void myStack_test_function() {
    myStack<int> st;
    int op, in;
    while (cin >> op) {
        if (op == 0) {
            cin >> in;
            st.push(in);
        } else if (op == 1) {
            st.pop();
        } else if (op == 2) {
            cout << st.top() << "\n";
        } else if (op == 3) {
            cout << (st.empty() ? "true" : "false")
                 << "\n";
        }
        st.print();
    }
}