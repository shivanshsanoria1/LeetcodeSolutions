class Solution {
public:
    bool find132pattern(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int minTillNow = nums[0];
        for(int j=1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
                if(nums[k] < nums[j] && minTillNow < nums[k])
                    return true;
            minTillNow = min(minTillNow, nums[j]);
        }
        return false;
    }
};
// minTillNow is equivalent to nums[i]