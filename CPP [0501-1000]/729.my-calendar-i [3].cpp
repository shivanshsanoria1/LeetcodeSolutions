class MyCalendar {
private:
    // {start, end} ('start' in inclusive, 'end' is exclusive)
    vector<pair<int, int>> intervals;

    // inserts an interval into intervals[] while keeping intervals[] sorted
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
    
    // T.C.=O(n + log(n))
    // n: num of times book() is called
    // Binary-Search + maintained sorted vector
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
                
        insertInterval({s1, e1});

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