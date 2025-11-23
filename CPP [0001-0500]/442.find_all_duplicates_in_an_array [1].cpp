class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    vector<int> findDuplicates(vector<int>& nums) { 
        int n=nums.size();
        vector<int> ans;

        if(n < 2)
            return ans;

        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++)
            if(nums[i] == nums[i-1])
                ans.push_back(nums[i]);
                
        return ans;
    }
};