class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(1)
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int sum1 = 0;
        for(int num: nums1)
            sum1 += num;

        long long int sum2 = 0;
        for(int num: nums2)
            sum2 += num;

        int zeros1 = count(nums1.begin(), nums1.end(), 0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);

        // replace every 0 in nums1[] and nums2[] with 1
        sum1 += zeros1;
        sum2 += zeros2;

        if((sum1 < sum2 && zeros1 == 0) || (sum1 > sum2 && zeros2 == 0))
            return -1;

        return max(sum1, sum2);
    }
};