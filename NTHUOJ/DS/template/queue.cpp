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