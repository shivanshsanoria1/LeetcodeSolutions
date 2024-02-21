class MyCircularDeque {
private:
    vector<int> q;
    int front, rear;
    int size;

public:
    MyCircularDeque(int k) {
        q.resize(k, -1); // set the size of vector as k, -1: empty space
        front = -1;
        rear = -1;
        size = k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(isEmpty()) // 1st element is inserted in queue
        {
            front = 0;
            rear = 0;
        }
        else
            front = (front == 0) ? size-1 : front-1;
        q[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
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
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        q[front] = -1; // [Not required] reset the value at front
        // only 1 element in queue, reset front and rear
        if(front == rear) 
        {
            front = -1; 
            rear = -1;
        }
        else
            front = (front+1) % size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        q[rear] = -1; // [Not required] reset the value at rear
        // only 1 element in queue, reset front and rear
        if(front == rear)
        { 
            front = -1; 
            rear = -1;
        }
        else
            rear = (rear == 0) ? size-1 : rear-1;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : q[front];
    }
    
    int getRear() {
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */