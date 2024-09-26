class MyCalendar {
private:
    // time -> count of net intervals added (+) or removed (-) at this time
    map<int, int> mp;

public:
    MyCalendar() {
        this->mp.clear();
    }
    
    // T.C.=O(n*(n + log(n)))
    // n: num of times book() is called
    // Line-Sweep algo.
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int currCount = 0;

        for(auto [time, count]: mp)
        {
            currCount += count;

            // 2 intervals present at curr time 
            if(currCount == 2)
            {
                // remove the [start, end) interval from map
                mp[start]--;
                mp[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */