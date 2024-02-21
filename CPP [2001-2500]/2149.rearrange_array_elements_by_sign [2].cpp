class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i = 0, j = 1;
        for(int num: nums)
        {
            if(num > 0)
            {
                ans[i] = num;
                i += 2;
            }
            else // num < 0
            {
                ans[j] = num;
                j += 2;
            }
        }
        return ans;
    }
};