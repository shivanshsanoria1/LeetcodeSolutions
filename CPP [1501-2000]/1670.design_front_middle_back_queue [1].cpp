class FrontMiddleBackQueue {
private:
    list<int> nums;

public:
    FrontMiddleBackQueue() {
        this->nums.clear();
    }
    
    void pushFront(int val) {
        nums.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n=nums.size();
        int mid = n % 2 == 0 ? n/2 : (n-1)/2;
        auto itr = nums.begin();
        advance(itr, mid);
        nums.insert(itr, val);
    }
    
    void pushBack(int val) {
        nums.push_back(val);
    }
    
    int popFront() {
        if(nums.empty())
            return -1;

        int val = nums.front();
        nums.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(nums.empty())
            return -1;

        int n=nums.size();
        int mid = n % 2 == 0 ? n/2 - 1 : (n-1)/2;
        auto itr = nums.begin();
        advance(itr, mid);
        int val = *itr;
        nums.erase(itr);
        return val;
    }
    
    int popBack() {
        if(nums.empty())
            return -1;

        int val = nums.back();
        nums.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */