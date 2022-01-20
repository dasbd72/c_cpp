#include <iostream>
// MIN heap
template <class T>
class myHeap {
   private:
    T *arr;
    int capacity;
    int size;

   public:
    myHeap();
    ~myHeap();
    T top() const;
    void pop();
    void push(T e);
    bool empty() const;
    void extendCapacity();
};

template <class T>
myHeap<T>::myHeap() {
    size = 0;
    capacity = 1;
    arr = new T[capacity];
}

template <class T>
myHeap<T>::~myHeap() {
    delete[] arr;
}

template <class T>
T myHeap<T>::top() const {
    return this->arr[0];
}

template <class T>
void myHeap<T>::pop() {
    this->arr[0] = this->arr[--this->size];
    int curr = 0;
    while (true) {
        int left = curr * 2 + 1, right = curr * 2 + 2;
        if (right < this->size) {
            if (arr[curr] > arr[left] || arr[curr] > arr[right]) {
                if (arr[left] < arr[right]) {
                    std::swap(arr[curr], arr[left]);
                    curr = left;
                } else {
                    std::swap(arr[curr], arr[right]);
                    curr = right;
                }
            } else
                break;
        } else if (left < this->size) {
            if (arr[curr] > arr[left]) {
                std::swap(arr[curr], arr[left]);
                curr = left;
            } else
                break;
        } else
            break;
    }
}
template <class T>
void myHeap<T>::push(T e) {
    int curr = this->size++;
    if (this->capacity < this->size)
        this->extendCapacity();
    this->arr[curr] = e;
    while (curr > 0 && arr[(curr - 1) / 2] > arr[curr]) {
        std::swap(arr[(curr - 1) / 2], arr[curr]);
        curr = (curr - 1) / 2;
    }
}

template <class T>
bool myHeap<T>::empty() const {
    return this->size == 0;
}

template <class T>
void myHeap<T>::extendCapacity() {
    int oldCapacity = this->capacity;
    this->capacity *= 2;
    T *oldarr = arr;
    this->arr = new T[this->capacity];
    std::copy(oldarr, oldarr + oldCapacity, this->arr);
}

int main() {
    using namespace std;
    myHeap<int> hp;
    hp.push(1);
    hp.push(5);
    hp.push(2);
    hp.push(7);
    hp.push(3);

    while (!hp.empty()) {
        cout << hp.top() << " ";
        hp.pop();
    }
    cout << endl;
}