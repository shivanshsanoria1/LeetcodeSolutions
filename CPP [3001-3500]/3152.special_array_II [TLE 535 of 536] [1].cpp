class Solution {
public:
    // T.C.=O(q*n), S.C.=O(1)
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0], right = query[1];
            bool isValid = true;

            for(int i=left; i<right; i++)
                if(nums[i] % 2 == nums[i+1] % 2)
                {
                    isValid = false;
                    break;
                }

            ans.push_back(isValid);
        }

        return ans;
    }
};