class MyCircularDeque {
private:
    vector<int> q;
    int n = 0;
    int front = -1;
    int rear = -1;

public:
    MyCircularDeque(int k) {
        this->q.resize(k, -1);
        this->n = k;
        this->front = -1;
        this->rear = -1;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;

        // 1st element to be inserted in queue
        if(isEmpty()) 
        {
            front = 0;
            rear = 0;
        }
        else
            front = (front - 1 + n) % n;

        q[front] = value;

        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;

        // 1st element to be inserted in queue
        if(isEmpty()) 
        {
            front = 0;
            rear = 0;
        }
        else
            rear = (rear + 1) % n;

        q[rear] = value;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;

        // [Not required] reset the value at front
        q[front] = -1; 

        // only 1 element in queue, reset front and rear
        if(front == rear) 
        {
            front = -1; 
            rear = -1;
        }
        else
            front = (front + 1) % n;

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;

        // [Not required] reset the value at rear
        q[rear] = -1; 

        // only 1 element in queue, reset front and rear
        if(front == rear)
        { 
            front = -1; 
            rear = -1;
        }
        else
            rear = (rear - 1 + n) % n;

        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : q[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        return (rear + 1) % n == front;
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