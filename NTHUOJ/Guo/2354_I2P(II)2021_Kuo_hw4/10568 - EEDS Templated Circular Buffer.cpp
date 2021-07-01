#include <deque>
#include <iostream>

using namespace std;

/* Code for our templated circular buffer class goes here */
template <class T>
class circular_buffer {
    long long unsigned capacity;
    deque<T> arr;

   public:
    circular_buffer(long long unsigned capacity) : capacity(capacity) {
    }
    void pop_front() {
        if (!arr.empty()) arr.pop_front();
    }
    void push_back(T data) {
        if (arr.size() == capacity) pop_front();
        arr.push_back(data);
    }
    long long unsigned size() const {
        return arr.size();
    }
    T& operator[](long long unsigned idx) {
        return arr[idx];
    }
};

int main() {
    int capacity;
    cin >> capacity;
    circular_buffer<int> cbi(capacity);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_back") {
            int data;
            cin >> data;
            cbi.push_back(data);
        } else if (cmd == "pop_front") {
            cbi.pop_front();
        } else if (cmd == "print") {
            for (int j = 0; j < cbi.size(); j++) {
                cout << cbi[j] << endl;
            }
            cout << "----" << endl;
        }
    }
    return 0;
}