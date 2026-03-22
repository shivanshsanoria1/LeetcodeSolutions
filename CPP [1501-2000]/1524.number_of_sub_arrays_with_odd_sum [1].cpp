class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n), S.C.=O(1)
    int numOfSubarrays(vector<int>& arr) {
        int prefixSum = 0;
        // num of odd and even prefix sums found so far
        int oddPrefixSumCount = 0, evenPrefixSumCount = 0;

        int ans = 0;

        for(int num: arr)
        {
            prefixSum += num % 2;

            if(prefixSum % 2 == 1)
            {
                ans = (ans + 1) % MOD;
                ans = (ans + evenPrefixSumCount) % MOD;
                oddPrefixSumCount++;
            }
            else
            {
                ans = (ans + oddPrefixSumCount) % MOD;
                evenPrefixSumCount++;
            }
        }
        
        return ans;
    }
};
/* 
# imagine replacing each odd num by 1 and even num by 0
# if the curr prefix sum is odd then:
  the curr subarray can be paired with any of the
  previously seen subarrays with even prefix sum
  to obtain an odd sum
# if the curr prefix sum is even then:
  the curr subarray can be paired with any of the
  previously seen subarrays with odd prefix sum
  to obtain an odd sum
# in case of odd prefix sum an additional +1 is required 
  as the curr subarray doesn't need to be paired with 
  any other subarray to obtain an odd sum 
*/