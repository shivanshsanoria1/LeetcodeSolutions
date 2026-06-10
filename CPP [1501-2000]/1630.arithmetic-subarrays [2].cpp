class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool> ans(m, true);
        for(int i=0; i<m; i++)
        {
            int left = l[i], right = r[i];
            int maxNum = *max_element(nums.begin() + left, nums.begin() + right + 1);
            int minNum = *min_element(nums.begin() + left, nums.begin() + right + 1);
            if((maxNum - minNum) % (right - left) != 0)
            {
                ans[i] = false;
                continue;
            }

            int diff = (maxNum - minNum) / (right - left);
            if(diff == 0) // all nums in the range [left, right] are the same
                continue;
            unordered_set<int> s(nums.begin() + left, nums.begin() + right + 1);
            for(int j=1; j <= right-left; j++)
                if(s.find(minNum + j*diff) == s.end()) // not found in set
                {
                    ans[i] = false;
                    break;
                }
        }
        return ans;
    }
};
// T.C.=O(m*n), S.C.=O(n)