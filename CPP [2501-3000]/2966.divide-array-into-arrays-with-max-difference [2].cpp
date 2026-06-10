class Solution {
public:
    // T.C.=O(n + 50), S.C.=O(50)
    int missingInteger(vector<int>& nums) {
        int n=nums.size();

        int prefixSum = 0;
        for(int i=0; i<n; i++)
        {
            prefixSum += nums[i];
            if(i+1 < n && nums[i+1] - nums[i] != 1)
                break;
        }
        
        if(prefixSum > 50)
            return prefixSum;
        
        vector<bool> isPresent(51, false);
        for(int num: nums)
            isPresent[num] = true;
        
        for(int i=prefixSum; i<=50; i++)
            if(!isPresent[i])
                return i;

        return 51;
    }
};