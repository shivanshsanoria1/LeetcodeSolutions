class Solution {
private:
    typedef long long int lli;

public:
    long long maxAlternatingSum(vector<int>& nums) { // State-Space, T.C.=O(n), S.C.=O(1)
        lli S0 = 0;
        lli S1 = 0;
        for(int num: nums)
        {
            lli temp_S0 = S0;
            S0 = max(S0, S1 + num);
            S1 = max(S1, temp_S0 - num);
        }
        return S0;
    }
};
/*
# there are 2 states- S0, S1
# S0: +ive, S1: -ive
# from S0 we can stay at S0 by skipping nums[i] or 
  we can move to S1 by including nums[i] (with +ive sign)
# from S1 we can stay at S1 by skipping nums[i] or 
  we can move to S0 by including nums[i] (with -ive sign)
*/