class Solution {
private:
    bool isFound(vector<int>& nums, int key){
        for(int num: nums)
            if(num == key)
                return true;
        return false;
    }

public:
    // T.C.=O(n + ??), S.C.=O(1)
    int missingInteger(vector<int>& nums) {
        int n=nums.size();

        int prefixSum = 0;
        for(int i=0; i<n; i++)
        {
            prefixSum += nums[i];
            if(i+1 < n && nums[i+1] - nums[i] != 1)
                break;
        }
        
        while(isFound(nums, prefixSum))
            prefixSum++;
        
        return prefixSum;
    }
};