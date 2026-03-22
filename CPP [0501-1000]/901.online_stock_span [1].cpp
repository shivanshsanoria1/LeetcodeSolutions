class StockSpanner {
private:
    vector<int> vec; //stores values of prices
    stack<int> st; //maintain the stack in strictly decreasing order of prices, stores index instead of values
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && price >= vec[st.top()]) //keep popping elements while curr price >= stack.top
            st.pop();
        int prev_index= st.empty() ? -1 : st.top();
        vec.push_back(price); //push the curr price in vector
        st.push(vec.size()-1); //push the index of curr price in stack
        return st.top()-prev_index;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */