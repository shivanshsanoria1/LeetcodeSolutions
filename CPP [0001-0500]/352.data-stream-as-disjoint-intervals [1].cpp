class SummaryRanges {
private:
    set<int> s;

public:
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int value) { // T.C.=O(logn)
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() { // T.C.=O(n)
        vector<vector<int>> ans;
        for(int num: s)
        {
            // end point of last interval + 1 == curr num
            if(!ans.empty() && ans.back()[1] + 1 == num)
                // update the end point of last interval
                ans.back()[1] = num;
            // add a new interval with start and end points as curr num
            else
                ans.push_back({num, num});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */