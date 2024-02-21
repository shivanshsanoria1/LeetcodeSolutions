class FreqStack {
private:
    unordered_map<int, pair<int, stack<int>>> mp; // num -> {freq, stack{id}}
    int id;

public:
    FreqStack() {
        mp.clear();
        id = 0;
    }
    
    void push(int val) {
        id++;
        mp[val].first++;
        mp[val].second.push(id);
    }
    
    int pop() {
        int ans = -1;
        int maxFreq = 0;
        int maxId = 0;
        for(auto& it: mp)
        {
            int freq = it.second.first;
            stack st = it.second.second;
            int currId = !st.empty() ? st.top() : -1;
            // new max freq found
            if(freq > maxFreq) 
            {
                maxFreq = freq; // update the max freq
                maxId = currId; // update max id
                ans = it.first; // update ans with curr num
            }
            // another max freq found and with more recent id 
            else if(freq == maxFreq && currId > maxId)
            {
                maxId = currId; // update max id
                ans = it.first; // update ans with curr num
            }
        }
        mp[ans].first--; // decrement the freq of the num to be popped
        mp[ans].second.pop(); // remove the most recent id of the num to be popped
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */