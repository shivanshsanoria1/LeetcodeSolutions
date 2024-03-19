class MyCalendar {
private:
    // {start, end} ('start' in inclusive, 'end' is exclusive)
    set<pair<int, int>> intervals;

public:
    MyCalendar() {
        this->intervals.clear();
    }
    
    // T.C.=O(n^2)
    bool book(int start, int end) {
        int s2 = start, e2 = end;
        for(auto [s1, e1]: intervals)
        {
            if(s1 >= e2)
                break;
            if(s2 < e1)
                return false;
        }
                
        intervals.insert({s2, e2});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 // intervals [s1, e1) and [s2, e2) intersect 
 // if (s1 < e2) and (s2 < e1)