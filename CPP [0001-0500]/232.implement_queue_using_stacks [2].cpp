class MyQueue {
private:
    stack<int> st1; // primary stack
    stack<int> st2; // secondary stack

public:
    MyQueue() {
        
    }
    
    // T.C.=O(1)
    void push(int x) { 
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
        // empty stack2 into stack1
        while(!st2.empty()) 
        {
            st1.push(st2.top());
            st2.pop();
        }
        return popped;
    }
    
    // T.C.=O(n)
    int peek() { 
        // empty stack1 into stack2
        while(!st1.empty()) 
        {
            st2.push(st1.top());
            st1.pop();
        }
        // find stack2 top
        int top = st2.top();
        // empty stack2 into stack1
        while(!st2.empty()) 
        {
            st1.push(st2.top());
            st2.pop();
        }
        return top;
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