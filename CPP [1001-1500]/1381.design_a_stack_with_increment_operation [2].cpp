class CustomStack {
private:
    stack<int> st1, st2;
    int maxSize = -1;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st1.size() < maxSize)
            st1.push(x);
    }
    
    int pop() {
        if(st1.size() > 0)
        {
            int top = st1.top();
            st1.pop();
            return top;
        }
        return -1; // stack is empty
    }
    
    void increment(int k, int val) {
        int popCount = st1.size() >= k ? st1.size() - k : 0;
        while(popCount--)
        {
            st2.push(st1.top());
            st1.pop();
        }
        while(!st1.empty())
        {
            st2.push(st1.top() + val);
            st1.pop();
        }
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */