class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    // Greedy
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long int sum = 0;
        for(int i=0, j=nums.size()-1; i<j; i++, j-=2)
            sum += nums[j-1];

        return sum;
    }
};

/*
it is optimal to take the 2 largest elements (say, B and C) 
and 1 smallest element (say, A) thus forming the sequence A,B,C
the median B is added to the answer until no more size 3 sequence is left

# similar: [1561. maximum-number-of-coins-you-can-get]
*/