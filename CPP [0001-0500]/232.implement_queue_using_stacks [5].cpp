class MyQueue {
private:
    // acts as 'rear' of the queue for pushing the elements
    stack<int> in; 
    // acts as 'front' of the queue for popping the elements
    stack<int> out; 
    // act as the front element of the queue
    int front;

public:
    MyQueue() {
        front = -1;
    }
    
    // T.C.=O(1)
    void push(int x) { 
        // found the front of the queue
        if(in.empty())
            front = x;
        in.push(x);
    }
    
    // Amortized T.C.=O(1), Worst-case T.C.=O(n)
    int pop() { 
        // out stack is empty
        if(out.empty()) 
            // empty the 'in' stack into the 'out' stack
            while(!in.empty()) 
            {
                out.push(in.top());
                in.pop();
            }

        // pop from 'out' stack
        int popped = out.top();
        out.pop();

        return popped;
    }
    
    // T.C.=O(1)
    int peek() { 
        return !out.empty() ? out.top() : front;
    }
    
    // T.C.=O(1)
    bool empty() {
        return out.empty() && in.empty();
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