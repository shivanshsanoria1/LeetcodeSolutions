class Solution {
public:
    int maximumDifference(vector<int>& nums) { //T.C.=O(n^2)
        int n=nums.size(), max_diff=-1;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(nums[j]-nums[i] > 0)
                    max_diff=max(max_diff,nums[j]-nums[i]);
        return max_diff;
    }
};