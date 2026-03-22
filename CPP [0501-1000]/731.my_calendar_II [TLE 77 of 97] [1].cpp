class MyCalendarTwo {
private:
    // num -> freq
    unordered_map<int, int> mp;

public:
    MyCalendarTwo() {
        this->mp.clear();
    }
    
    // T.C.=O(n*(end - start))
    // n: num of times book() is called
    bool book(int start, int end) {
        for(int i=start; i<end; i++)
            if(mp[i] == 2)
                return false;

        for(int i=start; i<end; i++)
            mp[i]++;
            
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */