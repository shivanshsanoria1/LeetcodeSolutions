class Solution {
public:
    int maximumScore(vector<int>& nums, int k) { // T.C.=O(n), S.C.=O(1)
        int left = k-1, right = k+1;
        int minVal = nums[k];
        int ans = nums[k];

        while(left >= 0 && right < nums.size())
        {
            if(nums[left] > nums[right])
            {
                minVal = min(minVal, nums[left]);
                ans = max(ans, minVal * ((right-1) - (left) + 1));
                left--;
            }
            else
            {
                minVal = min(minVal, nums[right]);
                ans = max(ans, minVal * (right - (left+1) + 1));
                right++;
            }
        }

        while(left >= 0)
        {
            minVal = min(minVal, nums[left]);
            ans = max(ans, minVal * ((right-1) - (left) + 1));
            left--;
        }

        while(right < nums.size())
        {
            minVal = min(minVal, nums[right]);
            ans = max(ans, minVal * (right - (left+1) + 1));
            right++;
        }
        
        return ans;
    }
};