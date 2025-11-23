class MyCalendar {
private:
    // {start, end} ('start' in inclusive, 'end' is exclusive)
    vector<pair<int, int>> intervals;

public:
    MyCalendar() {
        this->intervals.clear();
    }
    
    // T.C.=O(n*log(n))
    // n: num of times book() is called
    // Binary-Search + Sorting
    bool book(int start, int end) {
        int s1 = start, e1 = end;
        int left = 0, right = intervals.size()-1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            auto [s2, e2] = intervals[mid];

            // move to the left-subarray
            if(e1 <= s2)
                right = mid - 1;
            // move to the right-subarray
            else if(e2 <= s1)
                left = mid + 1;
            // [s1, e1) and [s2, e2) intersect 
            else
                return false;
        }
                
        intervals.push_back({s1, e1});
        
        sort(intervals.begin(), intervals.end());

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