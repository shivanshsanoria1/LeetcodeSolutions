class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;

        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    ans = max(ans, nums[i] ^ nums[j]);
                    
        return ans;
    }
};