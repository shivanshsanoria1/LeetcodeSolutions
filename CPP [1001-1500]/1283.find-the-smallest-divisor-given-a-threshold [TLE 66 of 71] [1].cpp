class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    // m: max-val in nums[]
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxNum = *max_element(nums.begin(), nums.end());

        // range of values of divisor is [1, maxNum]
        for(int div = 1; div <= maxNum; div++)
        {
            long long int sum = 0;
            for(int num: nums)
            {
                // round-up division
                sum += num % div == 0 ? num/div : num/div + 1;
                if(sum > threshold)
                    break;
            }

            if(sum <= threshold)
                return div;
        }

        return -1;
    }
};