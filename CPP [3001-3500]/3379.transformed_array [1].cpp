class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int j = i;

            if(nums[i] > 0)
                j = (i + nums[i]) % n;
            else if(nums[i] < 0)
                j = (i + nums[i] + n*100) % n;

            ans.push_back(nums[j]);
        }

        return ans;
    }
};