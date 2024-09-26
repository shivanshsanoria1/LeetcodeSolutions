class MyCalendarTwo {
private:
    // time -> count of net intervals added (+) or removed (-) at this time
    map<int, int> mp;

public:
    MyCalendarTwo() {
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

            // 3 intervals present at curr time 
            if(currCount == 3)
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
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */