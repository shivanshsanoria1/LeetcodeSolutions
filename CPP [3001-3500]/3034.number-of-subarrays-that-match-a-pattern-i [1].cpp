class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        int m=pattern.size();
        int count = 0;
        for(int i=0; i<n-m; i++)
        {
            bool followsPattern = true;
            for(int k=0; k<m; k++)
            {
                bool cond1 = pattern[k] == 1 && nums[i+k] >= nums[i+k+1];
                bool cond2 = pattern[k] == 0 && nums[i+k] != nums[i+k+1];
                bool cond3 = pattern[k] == -1 && nums[i+k] <= nums[i+k+1];
                if(cond1 || cond2 || cond3)
                {
                    followsPattern = false;
                    break;
                }
            }
            if(followsPattern)
                count++;
        }
        return count;
    }
};