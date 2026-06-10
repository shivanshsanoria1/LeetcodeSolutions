class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1)
        {
            for(int i=0; i<nums.size()-1; i++)
                nums[i] = (nums[i] + nums[i+1]) % 10;
            nums.pop_back();
        }
        return nums[0];
    }
};