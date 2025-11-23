class MedianFinder {
private:
    vector<int> nums;

public:
    MedianFinder() {
        nums.clear();
    }
    
    void addNum(int num) { // T.C.=O(n)
        nums.push_back(num);
        for(int i=nums.size()-1; i>=1; i--)
        {
            if(nums[i-1] > nums[i])
                swap(nums[i-1], nums[i]);
            else
                break;
        }
    }
    
    double findMedian() { // T.C.=O(1)
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