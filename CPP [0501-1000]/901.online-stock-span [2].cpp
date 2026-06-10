class StockSpanner {
private:
    stack<pair<int,int>> st; //price -> index, maintain the stack in strictly decreasing order of prices
    int index;
    
public:
    StockSpanner() {
        index= -1;
    }
    
    int next(int price) {
        index++;
        while(!st.empty() && price >= st.top().first) //keep popping elements while curr price >= stack.top price
            st.pop();
        int prev_index= st.empty() ? -1 : st.top().second;
        st.push({price,index}); //push the curr price and its index in stack
        return index-prev_index;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */