class KthLargest {
private: 
    int k = 0;
    // min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int num: nums)
        {
            this->pq.push(num);
            if(this->pq.size() == k+1)
                this->pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() == k+1)
            pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */