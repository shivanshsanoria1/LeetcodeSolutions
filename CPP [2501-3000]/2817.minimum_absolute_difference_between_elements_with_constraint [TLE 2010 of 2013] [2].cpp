class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) { // T.C.=O(n^2), S.C.=O(1)
        if(x == 0)
            return 0;
        
        int n=nums.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
            for(int j=i+x; j<n; j++)
            {
                if(nums[i] == nums[j])
                    return 0;
                ans = min(ans, abs(nums[i] - nums[j]));
            }
        return ans;
    }
};