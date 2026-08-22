class Solution {
public:
    // T.C.=O(n^2 * log(m)), S.C.=O(1)
    // m: max val in nums[]
    long long maxPairStrength(vector<int>& nums) {
        long long maxStrength = 0;
        const int n = nums.size();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++){
                long long gcdVal = gcd(nums[i], nums[j]);
                maxStrength = max(maxStrength, (long long)nums[i]*nums[j]/(gcdVal*gcdVal));
            }

        return maxStrength;
    }
};