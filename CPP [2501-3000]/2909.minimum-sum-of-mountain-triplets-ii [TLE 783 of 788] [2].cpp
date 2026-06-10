class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int minSum = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int minLeft = INT_MAX, minRight = INT_MAX;

            for(int left = i-1; left >= 0; left--)
                if(nums[left] < nums[i])
                    minLeft = min(minLeft, nums[left]);
                    
            for(int right = i+1; right < n; right++)
                if(nums[i] > nums[right])
                    minRight = min(minRight, nums[right]);
            
            if(minLeft != INT_MAX && minRight != INT_MAX)
                minSum = min(minSum, minLeft + nums[i] + minRight);
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};