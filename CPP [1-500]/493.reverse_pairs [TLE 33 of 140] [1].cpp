class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i] > 2*nums[j])
                    count++;

        return count;
    }
};