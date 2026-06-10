class MedianFinder {
private:
    vector<int> nums;

public:
    MedianFinder() {
        nums.clear();
    }
    
    void addNum(int num) { // T.C.=O(1)
        nums.push_back(num);
    }
    
    double findMedian() { // T.C.=O(n*logn)
        sort(nums.begin(), nums.end());
        int n=nums.size();
        return (n % 2 == 1) ? nums[n/2] : (nums[n/2-1] + nums[n/2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */