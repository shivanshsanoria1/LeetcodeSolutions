class Solution {
public:
    // T.C.=O((n-k)*k + k), S.C.=O(1)
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flips = 0;

        for(int i=0; i<=n-k; i++)
        {
            if(nums[i] == 1)
                continue;

            flips++;
            // flip all the nums in index-range [i, i+k-1]
            for(int j=i; j<i+k; j++)
                nums[j] = !nums[j];
        }

        for(int i=n-k+1; i<n; i++)
            if(nums[i] == 0)
                return -1;

        return flips;
    }
};
// S.C. can also be considered O(n) as the input array is being modified