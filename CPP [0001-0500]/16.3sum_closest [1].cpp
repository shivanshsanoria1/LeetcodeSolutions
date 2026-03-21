class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) { // T.C.=O(n^3)
        int min=INT_MAX, n=nums.size(), sum;
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(abs(nums[i]+nums[j]+nums[k]-target) < min)
                    {
                        min=abs(nums[i]+nums[j]+nums[k]-target);
                        sum=nums[i]+nums[j]+nums[k];
                    }
        return sum;
    }
};