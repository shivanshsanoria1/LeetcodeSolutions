class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    // Sorting
    vector<int> singleNumber(vector<int>& nums) { 
        sort(nums.begin(), nums.end());

        int n=nums.size();

        vector<int> ans;
        // check if 0th element has freq 1
        if(nums[0] != nums[1])
            ans.push_back(nums[0]);
        // check if the last element has freq 1
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