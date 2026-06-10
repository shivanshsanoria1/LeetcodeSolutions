class CustomStack {
private:
    vector<int> st;
    // max-size of stack
    int n = 0;
    // index of the top element of stack
    int top = -1;

public:
    CustomStack(int maxSize) {
        this->st.resize(maxSize, -1);
        this->n = maxSize;
        this->top = -1;
    }
    
    // T.C.=O(1)
    void push(int x) {
        // stack is full, so cannot push
        if(top == n-1)
            return;

        // increment top and push the new val
        st[++top] = x;
    }
    
    // T.C.=O(1)
    int pop() {
        // stack is empty, so cannot pop
        if(top == -1)
            return -1;

        int val = st[top];
        // reset stack-top [not-required]
        st[top--] = -1;

        return val;
    }
    
    // T.C.=O(min(k, top))
    void increment(int k, int val) {
        // limit k to the num of elements currently in stack, ie, (top + 1)
        k = min(k, top + 1);
        
        // increment the first k elements, ie, 
        // all elements in index-range [0, k-1] by val
        for(int i=0; i<k; i++)
            st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */