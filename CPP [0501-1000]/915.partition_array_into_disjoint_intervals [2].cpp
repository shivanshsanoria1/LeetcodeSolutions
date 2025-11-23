class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        // minValsRight[i]: min-val in index-range [i, n-1]
        vector<int> minValsRight(n, -1);

        minValsRight[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            minValsRight[i] = min(nums[i], minValsRight[i+1]);

        int maxValLeft = 0;

        for(int i=0; i<n-1; i++)
        {
            // max-val in index-range [0, i]
            maxValLeft = max(maxValLeft, nums[i]);

            // max-val in index-range [0, i] <=
            // min-val in index-range [i+1, n-1] 
            if(maxValLeft <= minValsRight[i+1])
                return i+1;
        }

        return -1;
    }
};