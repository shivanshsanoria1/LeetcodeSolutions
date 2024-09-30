class CustomStack {
private:
    // to store the elements
    vector<int> st;
    // to store the val by which each elemnt must be incremented
    vector<int> prefix;
    // max-size of stack
    int n = 0;
    // index of the top element of stack
    int top = -1;

public:
    // Lazy-propagation
    CustomStack(int maxSize) {
        this->st.resize(maxSize, -1);
        this->prefix.resize(maxSize, 0);
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

        // val at stack top must be incremented by prefix[top]
        int val = st[top] + prefix[top];

        // carry over val of prefix[top] to prefix[top - 1] (if it exists)
        if(top - 1 >= 0)
            prefix[top - 1] += prefix[top];
        
        // reset prefix[top]
        prefix[top] = 0;
        // reset stack-top [not-required]
        st[top] = -1;

        // decrement top to simulate pop
        top--;

        return val;
    }
    
    // T.C.=O(1)
    void increment(int k, int val) {
        // stack is empty
        if(top == -1)
            return;

        // limit k to the num of elements currently in stack, ie, (top + 1)
        k = min(k, top + 1);

        // increment prefix[k-1] by val to simulate incrementing the first k elements, ie, 
        // all the elements in index-range [0, k-1] by val
        prefix[k-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// prefix[i]: val by which all elements in index-range [0, i] must be incremented