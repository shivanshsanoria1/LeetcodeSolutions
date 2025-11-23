class Solution {
public:
    // T.C.=O(??), S.C.=O(1)
    // Greedy
    int minPatches(vector<int>& nums, int n) {
        unsigned int limit = 0;
        int patches = 0;

        for(int num: nums)
        {
            while(limit < n && limit + 1 < num)
            {
                limit += limit + 1;
                patches++;
            }

            if(limit >= n)
                break;

            limit += num;
        }

        while(limit < n)
        {
            limit += limit + 1;
            patches++;
        }

        return patches;
    }
};
// limit: we can make all the sums in range [0, limit]

// prerequisite: [1798. maximum-number-of-consecutive-values-you-can-make]
// similar: [2952. minimum-number-of-coins-to-be-added]