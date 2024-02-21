class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) { // T.C=O(n)
        int n=nums.size(), left=0, right=n-1, k=n-1;
        vector<int> ans(n);
        while(left<=right)
        {
            if(abs(nums[left]) >= abs(nums[right]))
            {
                ans[k] = nums[left]*nums[left];
                left++;
            }
            else
            {
                ans[k] = nums[right]*nums[right];
                right--;
            }
            k--;
        }
        return ans;
    }
};