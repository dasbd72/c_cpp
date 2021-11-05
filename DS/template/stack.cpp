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