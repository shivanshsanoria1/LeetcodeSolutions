class Solution {
public:
    int longestSubarray(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int left = i-1, right = i+1;
            while(left >= 0)
            {
                if(nums[left] == 0)
                    break;
                left--;
            }
            while(right < n)
            {
                if(nums[right] == 0)
                    break;
                right++;
            }
            int curr = right - left - 2;
            ans = max(ans, curr);
        }
        return ans;
    }
};