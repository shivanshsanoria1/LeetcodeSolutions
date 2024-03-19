class MyCalendar {
private:
    // {start, end} ('start' in inclusive, 'end' is exclusive)
    vector<pair<int, int>> intervals;

public:
    MyCalendar() {
        this->intervals.clear();
    }
    
    // T.C.=O(n*logn)
    // Binary-Search + Sorting
    bool book(int start, int end) {
        int s2 = start, e2 = end;
        int left = 0, right = intervals.size()-1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            auto [s1, e1] = intervals[mid];

            // move to the right-subarray
            if(s2 >= e1)
                left = mid + 1;
            // move to the left-subarray
            else if(e2 <= s1)
                right = mid - 1;
            // [s1, e1) and [s2, e2) intersect 
            else
                return false;
        }
                
        intervals.push_back({s2, e2});
        sort(intervals.begin(), intervals.end());

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