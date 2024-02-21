class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) { // T.C.=O(n) , S.C.=O(1)
        int n=nums.size();
        vector<int> ans;
        if(n<2)
            return ans;
        for(int i=0; i<n; i++) // nums[i] points to nums[abs(nums[i])-1]]
        {
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]; // change the sign of element at index [abs(nums[i])-1]
            if(nums[abs(nums[i])-1] > 0) // if element at index [abs(nums[i])-1] is +ive, then
                ans.push_back(abs(nums[i])); // abs(nums[i]) is the duplicate
        }
        return ans;
    }
};