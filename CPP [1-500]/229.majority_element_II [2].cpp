class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> ans;
        if(n == 1 || (n == 2 && nums[0] != nums[1]))
            ans.push_back(nums[0]);
        int count = 1;
        for(int i=1; i<n; i++)
        {
            count = nums[i-1] == nums[i] ? count + 1 : 1;
            if(count > n/3 && (ans.empty() || ans.back() != nums[i]))
                ans.push_back(nums[i]);
        }
        return ans;
    }
};