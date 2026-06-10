class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            int maxVal = 0;

            for(int j=i; j<n; j++)
            {
                maxVal = max(maxVal, nums[j]);

                if(maxVal > right)
                    break;

                if(maxVal >= left)
                    count++;
            }
        }

        return count;
    }
};