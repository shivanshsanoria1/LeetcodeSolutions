class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 2 largest numbers
        int max1 = nums[n-1], max2 = nums[n-2];
        // 2 smallest numbers
        int min1 = nums[0], min2 = nums[1];

        // +ive and -ive infinities
        const long long int INF_P = pow(10, 5);
        const long long int INF_N = -pow(10, 5);

        long long int ans = 0;

        // 2 largest numbers are +ive
        if(max2 > 0)
            ans = max(ans, INF_P * max1 * max2);
        // 2 smallest numbers are -ive
        if(min2 < 0)
            ans = max(ans, INF_P * min1 * min2);
        // largest number is +ive and smallest number is -ive
        if(max1 > 0 && min1 < 0)
            ans = max(ans, INF_N * max1 * min1);
        // 0
        return ans;
    }
};

/*
# we have to maximize the product of 3 numbers 
  where we have to replace a number with any number in range [-10^5, +10^5]
# which basically boils down to 3 choice {-10^5, 0, +10^5} for optimal solution
# -10^5 and +10^5 can be treated as -ive and +ive Infinities respectively

# Let the 2 other nums from nums[] be (x,y)
# there are basically 7 choices for the product:

1. + (++) -> + (choose the 2 most +ive numbers)
2. + (--) -> + (choose the 2 most -ive numbers)
3. + (+-) -> - (discard)
4. - (++) -> - (discard)
5. - (--) -> - (discard)
6. - (+-) -> + (choose most +ive and most -ive number)
7. 0 (++, --, +-) -> 0 (default)

# only cases 1,2,6 needs to be checked
# cases 4,5,6 always produce a -ive result so we can just discard them
  since we can always choose the case 7 over them to produce a product of 0
*/