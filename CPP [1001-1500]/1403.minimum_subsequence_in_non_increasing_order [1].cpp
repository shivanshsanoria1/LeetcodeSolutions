class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        int totalSum = 0;
        for(int num: nums)
            totalSum += num;
        sort(nums.begin(), nums.end());
        int sum = 0;
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--)
        {
            ans.push_back(nums[i]);
            sum += nums[i];
            if(sum > totalSum/2)
                break;
        }
        return ans;
    }
};