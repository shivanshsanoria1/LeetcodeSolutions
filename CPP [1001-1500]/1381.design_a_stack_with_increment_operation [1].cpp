class CustomStack {
private:
    vector<int> st;
    int maxSize = -1;
    int top = -1;

public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
        this->maxSize = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top < maxSize-1)
            st[++top] = x;
    }
    
    int pop() {
        if(top >= 0)
            return st[top--];
        return -1; // stack is empty
    }
    
    void increment(int k, int val) {
        if(k > maxSize) // limit k to maxSize
            k = maxSize;
        for(int i=0; i<k; i++) // increment the first k elements by val
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