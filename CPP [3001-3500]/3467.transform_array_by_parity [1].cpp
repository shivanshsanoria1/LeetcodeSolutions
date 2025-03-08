class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> transformArray(vector<int>& nums) {
        int evenCount = 0;
        for(int num: nums)
            if(num % 2 == 0)
                evenCount++;
        
        for(int i=0; i<evenCount; i++)
            nums[i] = 0;
        for(int i=evenCount; i<nums.size(); i++)
            nums[i] = 1;
        
        return nums;
    }
};