class MyCircularQueue {
private:
    vector<int> q;
    int front, rear;
    int size;

public:
    MyCircularQueue(int k) {
        q.resize(k); // set the size of vector as k
        front = -1;
        rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty()) // 1st element is inserted in queue
        {
            front = 0;
            rear = 0;
        }
        else
            rear = (rear+1) % size;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(front == rear) // only 1 element in queue
        { // reset front and rear
            front = -1; 
            rear = -1;
        }
        else
            front = (front+1) % size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return (front == -1 && rear == -1) ? true : false;
    }
    
    bool isFull() {
        return ((rear+1) % size == front) ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */