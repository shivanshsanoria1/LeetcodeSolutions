class ProductOfNumbers {
private:
    vector<int> nums;

public:
    ProductOfNumbers() {
        nums.clear();
    }
    
    void add(int num) { // T.C.=O(1)
        nums.push_back(num);
    }
    
    int getProduct(int k) { // T.C.=O(k)
        int n = nums.size();
        int pro = 1;
        for(int i=n-1; i>=n-k; i--)
        {
            if(nums[i] == 0)
                return 0;
            pro *= nums[i];
        }
        return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */