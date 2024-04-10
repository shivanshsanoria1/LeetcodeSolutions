class MKAverage {
private:
    int m = -1;
    int k = -1;

    queue<int> q;

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    
    // T.C.=O(1)
    void addElement(int num) {
        q.push(num);

        if(q.size() == m + 1)
            q.pop();
    }
    
    // T.C.=O(m*logm)
    int calculateMKAverage() {
        int size = q.size();

        if(size < m)
            return -1;

        vector<int> nums;

        while(size--)
        {
            int num = q.front();
            q.pop();

            nums.push_back(num);

            q.push(num);
        }

        sort(nums.begin(), nums.end());

        // find the sum (excluding the first and last k elements)
        int sum = 0;
        for(int i=k; i<m-k; i++)
            sum += nums[i];

        return sum / (m - 2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */