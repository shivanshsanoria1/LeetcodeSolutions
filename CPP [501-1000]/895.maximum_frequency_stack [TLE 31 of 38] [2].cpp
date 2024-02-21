class FreqStack {
private:
    unordered_map<int, int> freqs; // num -> freq
    unordered_map<int, vector<int>> ids; // num -> {id}
    int id;

public:
    FreqStack() {
        freqs.clear();
        ids.clear();
        id = 0;
    }
    
    void push(int val) {
        freqs[val]++;
        ids[val].push_back(++id);
    }
    
    int pop() {
        int ans = -1;
        int maxFreq = 0;
        int maxId = 0;
        for(auto& it: freqs)
        {
            int currNum = it.first;
            int currFreq = it.second;
            int currId = ids[currNum].size() > 0 ? ids[currNum].back() : -1;
            // new max freq found
            if(currFreq > maxFreq)
            {
                maxFreq = currFreq; // update the max freq
                maxId = currId; // update the max id
                ans = currNum; // update ans with curr num
            }
            // another max freq found and with more recent id 
            else if(currFreq == maxFreq && currId > maxId)
            {
                maxId = currId; // update the max id
                ans = currNum; // update ans with curr num
            }
        }
        freqs[ans]--; // decrement the freq of the num to be popped
        ids[ans].pop_back(); // remove the most recent id of the num to be popped
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */