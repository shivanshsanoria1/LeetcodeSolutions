class Solution {
private:
    typedef long long int lli;

public:
    long long maxAlternatingSum(vector<int>& nums) { // Tabulation, T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        vector<lli> dpPos(n);
        vector<lli> dpNeg(n);
        dpPos[0] = nums[0];
        dpNeg[0] = 0;
        for(int i=1; i<n; i++)
        {
            dpPos[i] = max(dpPos[i-1], dpNeg[i-1] + nums[i]);
            dpNeg[i] = max(dpNeg[i-1], dpPos[i-1] - nums[i]);
        }
        return dpPos[n-1];
    }
};