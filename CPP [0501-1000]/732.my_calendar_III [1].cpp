class MyCalendarThree {
private:
    // time -> count of net intervals added (+) or removed (-) at this time
    map<int, int> mp;

public:
    MyCalendarThree() {
        this->mp.clear();
    }
    
    // T.C.=O(n*(n + log(n)))
    // n: num of times book() is called
    // Line-Sweep algo.
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int currCount = 0;
        int maxCount = 0;

        for(auto [time, count]: mp)
        {
            currCount += count;
            maxCount = max(maxCount, currCount);
        }

        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */