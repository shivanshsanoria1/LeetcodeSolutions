class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++)
            if(nums[i] == nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }

        vector<int> ans;
        int zeros = 0;
        for(int num: nums)
        {
            if(num == 0)
                zeros++;
            else
                ans.push_back(num);
        }
        while(zeros--)
            ans.push_back(0);
        return ans;
    }
};