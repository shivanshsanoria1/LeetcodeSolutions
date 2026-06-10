class Solution {
private:
    #define MOD int(1e9 + 7)
    
public:
    // T.C.=O(k*n), S.C.=O(1)
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--)
        {
            int minVal = INT_MAX;
            int idx = -1;
            for(int i=0; i<nums.size(); i++)
                if(nums[i] < minVal)
                {
                    minVal = nums[i];
                    idx = i;
                }

            nums[idx] = ((long long int)nums[idx] * multiplier) % MOD;
        }

        return nums;
    }
};