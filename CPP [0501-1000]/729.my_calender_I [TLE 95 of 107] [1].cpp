class MyCalendar {
private:
    unordered_set<int> nums;

public:
    MyCalendar() {
        this->nums.clear();
    }
    
    // T.C.=O(n*(end - start))
    // n: num of times book() is called
    bool book(int start, int end) {
        for(int i=start; i<end; i++)
            if(nums.find(i) != nums.end())
                return false;

        for(int i=start; i<end; i++)
            nums.insert(i);
            
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */