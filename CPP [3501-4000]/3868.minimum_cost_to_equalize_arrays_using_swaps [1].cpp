class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        // 1. mark the freq of each num from both nums1[] and nums2[] in mp
        // num -> freq
        unordered_map<int, int> mp;
        for(const int num: nums1)
            mp[num]++;
        for(const int num: nums2)
            mp[num]++;
        
        // 2. every num must have even freq for it 
        // to be present in both the vectors finally
        for(const auto [num, freq]: mp)
            if(freq % 2 == 1)
                return -1;
        
        // 3. mark the freq of each num in nums1[] in mp1 and
        // make sure each num from nums2[] is also present in mp1 
        // (without any contribution in freq, ie, 0)
        // num -> freq
        unordered_map<int, int> mp1;
        for(const int num: nums1)
            mp1[num]++;
        for(const int num: nums2)
            mp1[num] += 0;

        // 4. the nums with extra freq in nums1[] must be swapped
        // and each swap adjusts the nums with extra freq in nums2[]
        int swaps = 0;
        for(const auto [num1, freq1]: mp1)
            if(freq1 > mp[num1]/2)
                swaps += freq1 - mp[num1]/2;

        return swaps;
    }
};