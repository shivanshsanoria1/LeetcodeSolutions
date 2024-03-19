class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // since min value of nums[i] is 1 so min possible product is 1
        // ie, there are no subarrays with product 0
        if(k == 0)
            return 0;

        int n=nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int pro = 1;
            for(int j=i; j<n; j++)
            {
                pro *= nums[j];
                if(pro >= k)
                    break;
                count++;
            }
        }
        return count;
    }
};