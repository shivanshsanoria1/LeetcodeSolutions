class Solution {
public:
    // T.C.=O(n*log(m)), S.C.=O(1)
    // m: max-val in nums[]
    // Binary-search
    int smallestDivisor(vector<int>& nums, int threshold) {
        // range of values of divisor is [1, maxNum]
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int divisor = -1;

        while(left <= right)
        {
            // divisor
            int mid = left + (right - left)/2;

            long long int sum = 0;
            for(int num: nums)
            {
                // round-up division
                sum += num % mid == 0 ? num/mid : num/mid + 1;
                if(sum > threshold)
                    break;
            }

            if(sum <= threshold)
            {
                divisor = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return divisor;
    }
};