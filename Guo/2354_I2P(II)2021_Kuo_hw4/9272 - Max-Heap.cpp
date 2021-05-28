#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    priority_queue<int, vector<int>, less<int>> heap;
    string op;
    while (cin >> op) {
        if (op == "PUSH") {
            int x;
            cin >> x;
            heap.push(x);
        } else if (op == "POP") {
            if (!heap.empty())
                heap.pop();
        } else {
            if (!heap.empty())
                cout << heap.top() << endl;
            else
                cout << "Null\n";
        }
    }
}