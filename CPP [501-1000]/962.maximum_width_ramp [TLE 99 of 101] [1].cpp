class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;

        for(int i=0; i<n-1; i++)
            for(int j=n-1; j>i; j--)
                if(nums[i] <= nums[j])
                {
                    maxWidth = max(maxWidth, j-i);
                    break;
                }
        
        return maxWidth;
    }
};

// similar: [739. daily-temperatures]