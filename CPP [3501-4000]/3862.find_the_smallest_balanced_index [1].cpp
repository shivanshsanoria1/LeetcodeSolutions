class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = 0;
        for(int num: nums)
            sum += num;

        long long prod = 1;
        // max possible sum = 10^9 * 10^5 = 10^14
        const long long LIMIT = 1e14;
        int idx = -1;
        for(int i=nums.size()-1; i>=0; i--){
            // prefix-sum in range [0, i-1]
            // for the curr iteration
            sum -= nums[i];

            if(sum == prod)
                idx = i;

            // prod * nums[i] > LIMIT
            if(prod > LIMIT / nums[i])
                break;
            // postfix-product in range [i, n-1]
            // for the next iteration
            prod *= nums[i];
        }

        return idx;
    }
};

/*
iterate from right to left so that the 
suffix product can be calculated by simply multipying the ith num at each step 
and the 
prefix sum can be calculated by simply subtracting the ith num at each step 

iterating from left to right will not work due to the fact that the 
subtraction is the inverse of addition 
but 
division is not the exact inverse of multiplication
*/