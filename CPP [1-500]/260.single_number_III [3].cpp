class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int n=nums.size();

        vector<int> ans;
        if(nums[0] != nums[1])
            ans.push_back(nums[0]);
        if(nums[n-2] != nums[n-1])
            ans.push_back(nums[n-1]);
        if(ans.size() == 2)
            return ans;

        for(int i=1; i<n-1; i++)
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1])
            {
                ans.push_back(nums[i]);
                if(ans.size() == 2)
                    return ans;
            }
            
        return ans;
    }
};