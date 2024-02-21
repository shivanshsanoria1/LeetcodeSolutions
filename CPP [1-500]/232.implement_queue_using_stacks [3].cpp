class MyQueue {
private:
    stack<int> st1; // primary stack
    stack<int> st2; // secondary stack
    int front; // front element of the queue

public:
    MyQueue() {
        front = -1;
    }
    
    // T.C.=O(1)
    void push(int x) { 
        // found the front of the queue
        if(st1.empty())
            front = x;
        st1.push(x);
    }
    
    // T.C.=O(n)
    int pop() { 
        // empty stack1 into stack2
        while(!st1.empty()) 
        {
            st2.push(st1.top());
            st1.pop();
        }
        // pop from stack2
        int popped = st2.top();
        st2.pop();
        // update the new front of the queue
        if(!st2.empty())
            front = st2.top();
        // empty stack2 into stack1
        while(!st2.empty()) 
        {
            st1.push(st2.top());
            st2.pop();
        }
        return popped;
    }
    
    // T.C.=O(1)
    int peek() { 
        return front;
    }
    
    // T.C.=O(1)
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */