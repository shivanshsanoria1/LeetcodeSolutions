class MinStack {
private:
    stack<int> st1; //stack to push values in
    stack<int> st2; //stack to maintain min value corresponding to each value in stack1
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || val < st2.top()) //push the curr val in stack2 if the stack is empty or a new min val is found
            st2.push(val);
        else //push the curr top of stack2 in stack2
            st2.push(st2.top());
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */