class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int maxValLeft = 0;

        for(int i=0; i<n-1; i++)
        {
            // max-val in index-range [0, i]
            maxValLeft = max(maxValLeft, nums[i]);

            // min-val in index-range [i+1, n-1]
            int minValRight = *min_element(nums.begin() + i+1, nums.end());

            // max-val in index-range [0, i] <=
            // min-val in index-range [i+1, n-1] 
            if(maxValLeft <= minValRight)
                return i+1;
        }

        return -1;
    }
};