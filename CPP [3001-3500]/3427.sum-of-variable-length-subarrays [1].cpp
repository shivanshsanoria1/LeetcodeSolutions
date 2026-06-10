class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;

        for(int i=0; i<n; i++)
            for(int j=max(0, i-nums[i]); j<=i; j++)
                sum += nums[j];

        return sum;
    }
};