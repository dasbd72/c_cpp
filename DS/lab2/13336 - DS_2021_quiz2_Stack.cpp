#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<unsigned long long, unsigned long long> matrix;

template <class T>
class myStack {
   private:
    T* myArray;
    int topidx, capacity;

   public:
    myStack() {
        topidx = -1;
        capacity = 1;
        myArray = new T[1];
    }
    ~myStack() {
        delete[] myArray;
    }
    bool empty() {
        return topidx == -1;
    }
    void pop() {
        topidx--;
        return;
    }
    T top() {
        return myArray[topidx];
    }
    void extendCapacity() {
        T* tmpArray;
        tmpArray = myArray;
        myArray = new T[capacity * 2];
        for (int i = 0; i < capacity; i++) myArray[i] = tmpArray[i];
        capacity *= 2;
        delete[] tmpArray;
    }
    void push(T item) {
        if (topidx == capacity - 1) this->extendCapacity();
        myArray[++topidx] = item;
        return;
    }
};

int main() {
    int T, Q;
    unsigned long long N, M;
    char C;
    matrix mat[26];

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> C >> N >> M;
        mat[C - 'A'] = make_pair(N, M);
    }

    cin >> Q;
    while (Q--) {
        myStack<matrix> st;
        unsigned long long sum = 0;
        bool valid = true;
        int explen = 0;
        char exp[2005];

        cin >> exp;
        explen = strlen(exp);
        for (int i = 0; i < explen && valid; i++) {
            if (exp[i] == '(') {
                st.push(make_pair(0, 0));
            } else if (exp[i] == ')') {
                matrix lmat, rmat;
                if (st.empty()) valid = false;
                rmat = st.top();
                st.pop();
                lmat = st.top();
                st.pop();
                st.pop();
                if (lmat.second != rmat.first)
                    valid = false;
                else {
                    sum += lmat.first * lmat.second * rmat.second;
                    st.push(make_pair(lmat.first, rmat.second));
                }

            } else {
                st.push(mat[exp[i] - 'A']);
            }
            if (!valid) break;
        }
        if (!valid)
            cout << "error\n";
        else
            cout << sum << "\n";
    }

    return 0;
}
