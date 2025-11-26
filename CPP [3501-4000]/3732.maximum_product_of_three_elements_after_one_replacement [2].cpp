class Solution {
private:
    vector<int> find2LargestAndSmallestNumbers(vector<int>& nums){
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for(int num: nums){
            if(num >= max1){
                max2 = max1;
                max1 = num;
            }else if(num > max2)
                max2 = num;
            
            if(num <= min1){
                min2 = min1;
                min1 = num;
            }else if(num < min2)
                min2 = num;
        }

        return {min1, min2, max2, max1};
    }

public:
    // T.C.=O(n), S.C.=O(1)
    long long maxProduct(vector<int>& nums) {
        vector<int> res = find2LargestAndSmallestNumbers(nums);
        // 2 smallest numbers
        int min1 = res[0], min2 = res[1];
        // 2 largest numbers
        int max2 = res[2], max1 = res[3];

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