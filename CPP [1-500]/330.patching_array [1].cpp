class Solution {
public:
    // T.C.=O(??), S.C.=O(1)
    // Greedy
    int minPatches(vector<int>& nums, int n) {
        unsigned int prefixSum = 0;
        int patches = 0;

        for(int num: nums)
        {
            while(prefixSum < n && num > prefixSum + 1)
            {
                prefixSum += prefixSum + 1;
                patches++;
            }

            if(prefixSum >= n)
                break;

            prefixSum += num;
        }

        while(n > prefixSum + 1)
        {
            prefixSum += prefixSum + 1;
            patches++;
        }

        return patches;
    }
};
// prerequisite: [1798. maximum-number-of-consecutive-values-you-can-make]