class Solution {
public:
    // T.C.=O(n1 + n2 + n2 * (max1/(min2*k))), S.C.=O(n1 + n2)
    // max1, min2: max and min elements in nums1[] and nums2[] respectively
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int max1 = *max_element(nums1.begin(), nums1.end());

        unordered_map<int, int> mp1;
        for(int num1: nums1)
            mp1[num1]++;
        
        unordered_map<int, int> mp2;
        for(int num2: nums2)
            mp2[num2]++;
        
        long long int count = 0;
        for(auto [num2, freq2]: mp2)
            // count the multiples of num2*k in nums1[]
            for(int mul = num2*k; mul <= max1; mul += num2*k)
                count += (long long int)freq2 * mp1[mul];

        return count;
    }
};
/*
# we need to count the pairs (num1, num2) satisfing the condition: 
  num1 % (num2 * k) == 0
# ie, how many times num1 is divisible by (num2 * k)
# in other words, how many times num1 is a multiple of (num2 * k)
*/