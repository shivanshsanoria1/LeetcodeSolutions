class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int sum = nums[0];
        int correctSum = (n*(n+1))/2;
        for(int i=1; i<n; i++)
        {
            if(nums[i] == nums[i-1]) // found duplicate
                ans[0] = nums[i];
            sum += nums[i];
        }
        ans[1] = ans[0] + correctSum - sum;
        return ans;
    }
};