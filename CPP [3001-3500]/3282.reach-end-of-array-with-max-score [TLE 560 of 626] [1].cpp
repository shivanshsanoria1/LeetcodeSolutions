class Solution {
private:
    typedef long long int lli;

    lli solve(vector<int>& nums, int i){
        lli res = 0;
        for(int j=i+1; j<nums.size(); j++)
            res = max(res, (lli)nums[i]*(j-i) + solve(nums, j));

        return res;
    }

public:
    // T.C.=O(n^n), S.C.=O(n)
    // Recursion
    long long findMaximumScore(vector<int>& nums) {
        return solve(nums, 0);
    }
};