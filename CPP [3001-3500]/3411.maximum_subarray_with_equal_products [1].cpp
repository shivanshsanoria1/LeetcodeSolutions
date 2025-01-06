class Solution {
public:
    // T.C.=O(n^2 * log(m)), S.C.=O(1)
    // m: max-val in nums[]
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;

        for(int i=0; i<n-1; i++)
        {
            int gcdVal = nums[i];
            int lcmVal = nums[i];
            int prod = nums[i];

            for(int j=i+1; j<n; j++)
            {
                gcdVal = __gcd(gcdVal, nums[j]);
                lcmVal = (lcmVal * nums[j]) / __gcd(lcmVal, nums[j]);
                prod *= nums[j];

                if(prod != gcdVal * lcmVal)
                    break;

                maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
};

// formula used: a * b = gcd(a, b) * lcm(a, b)