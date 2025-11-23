class FreqStack {
private:
    unordered_map<int, int> mp; // num -> freq
    unordered_map<int, vector<int>> groups; // freq -> {num}
    int maxFreq;

public:
    FreqStack() {
        mp.clear();
        groups.clear();
        maxFreq = 0;
    }
    
    void push(int val) {
        mp[val]++; // increment the freq of val
        maxFreq = max(maxFreq, mp[val]); // find the new possible max freq
        groups[mp[val]].push_back(val); // add the val to its max freq group
    }
    
    int pop() {
        int ans = groups[maxFreq].back();
        mp[ans]--; // decrement the freq of the most recent num in the max freq group
        groups[maxFreq].pop_back(); // remove the most recent num from the max freq group
        if(groups[maxFreq].size() == 0) // max freq group becomes empty
            maxFreq--; // decrement the max freq
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */