class MyCalendar {
private:
    // {start, end} ('start' in inclusive, 'end' is exclusive)
    vector<pair<int, int>> intervals;

    // inserts 'interval' into 'intervals' while keeping 'intervals' sorted
    void insertInterval(pair<int, int> interval) {
        intervals.push_back({interval.first, interval.second});
    
        for(int i=intervals.size()-2; i>=0; i--)
        {
            auto [s1, e1] = intervals[i];
            auto [s2, e2] = intervals[i+1];

            if(s1 > s2)
                swap(intervals[i], intervals[i+1]);
            else
                break;
        }
    }

public:
    MyCalendar() {
        this->intervals.clear();
    }
    
    // T.C.=O(n + logn)
    // Binary-Search + maintained sorted vector
    bool book(int start, int end) {
        int s2 = start, e2 = end;
        int left = 0, right = intervals.size()-1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
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

        // at this point [s1, e1) and [s2, e2) do not intersect 
        insertInterval({s2, e2});

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