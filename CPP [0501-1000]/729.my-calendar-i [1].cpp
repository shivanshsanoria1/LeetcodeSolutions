class MyCalendar {
private:
    // {start, end} ('start' in inclusive, 'end' is exclusive)
    vector<pair<int, int>> intervals;

public:
    MyCalendar() {
        this->intervals.clear();
    }
    
    // T.C.=O(n^2)
    // n: num of times book() is called
    bool book(int start, int end) {
        int s1 = start, e1 = end;
        
        for(auto [s2, e2]: intervals)
            if(!(e1 <= s2 || e2 <= s1))
                return false;
                
        intervals.push_back({s1, e1});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// 2 intervals [s1, e1) and [s2, e2) 
// don't intersect if: 
// e1 <= s2 or e2 <= s1