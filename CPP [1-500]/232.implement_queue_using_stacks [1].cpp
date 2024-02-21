class MyQueue {
private:
    stack<int> st1; // primary stack
    stack<int> st2; // secondary stack

public:
    MyQueue() {
        
    }
    
    // T.C.=O(n)
    void push(int x) { 
        // empty stack1 into stack2
        while(!st1.empty()) 
        {
            st2.push(st1.top());
            st1.pop();
        }
        // push curr into stack2
        st2.push(x); 
        // empty stack2 into stack1
        while(!st2.empty()) 
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // T.C.=O(1)
    int pop() { 
        int popped = st1.top();
        st1.pop();
        return popped;
    }
    
    // T.C.=O(1)
    int peek() { 
        return st1.top();
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